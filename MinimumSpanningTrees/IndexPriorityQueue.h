//
//  IndexPriorityQueue.h
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-26.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef MinimumSpanningTrees_IndexPriorityQueue_h
#define MinimumSpanningTrees_IndexPriorityQueue_h

#include <functional>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

template<typename KeyType, typename cmp = less<KeyType>>
class IndexPriorityQueue{
private:
    size_t              heapSize_;
    vector<KeyType>     data_;
    //the cleverest point in this data structor is that we simply manipulate
    //around the index, not the KeyType
    vector<size_t>      heap_;
    vector<size_t>      indexToPosition_;  //index -> position in heap_
    
private:
    void   exchange(size_t l, size_t r)
    {
        swap(heap_[l], heap_[r]);
        //maintain the index -> position array
        indexToPosition_[heap_[l]] = l;
        indexToPosition_[heap_[r]] = r;
    }
    
    bool   compare(size_t lprior, size_t rprior) const
    {
        return cmp()(data_[heap_[lprior]], data_[heap_[rprior]]);
    }
    
    size_t getParent(size_t child) const
    {
        if(child == 0)
        {
            return 0;
        }
        return (child + 1) / 2 - 1;
    }
    
    size_t getLchild(size_t parent) const
    {
        return 2 * parent + 1;
    }
   
    size_t getLastNoneLeaf() const
    {
        return heapSize_ / 2 - 1;
    }
    
    void   sink(size_t prior)
    {
        while(getLchild(prior) < heapSize_)
        {
            auto lchild = getLchild(prior);
            
            if(lchild + 1 < heapSize_ && compare(lchild + 1, lchild))
            {
                ++lchild;
            }
            if(compare(lchild, prior))
            {
                exchange(lchild, prior);
                prior = lchild;
            }
            else
            {
                break;
            }
        }
    }

    void   swim(size_t prior)
    {
        while(prior > 0 && compare(prior, getParent(prior)))
        {
            auto parent = getParent(prior);
            exchange(prior, parent);
            prior = parent;
        }
    }
    
public:
    explicit IndexPriorityQueue(size_t capacity):
        data_(capacity),
        heapSize_(0),
        heap_(capacity),
        indexToPosition_(capacity, -1)
    {
        
    }
    
    IndexPriorityQueue(const vector<KeyType> &item):
        data_(item),
        heapSize_(item.size()),
        heap_(item.size()),
        indexToPosition_(item.size(), -1)
    {
        for(auto i = 0; i < item.size(); ++i)
        {
            heap_[i] = i;
            indexToPosition_[heap_[i]] = i;
        }
        for(int i = getLastNoneLeaf(); i != -1; --i)
        {
            sink(i);
        }
    }
    
    IndexPriorityQueue(vector<KeyType> &&item):
        data_(std::move(item)),
        heapSize_(data_.size()),
        heap_(data_.size()),
        indexToPosition_(data_.size(), -1)
    {
        for(auto i = 0; i < data_.size(); ++i)
        {
            heap_[i] = i;
            indexToPosition_[heap_[i]] = i;
        }
        for(int i = getLastNoneLeaf(); i != -1; --i)
        {
            sink(i);
        }
    }
    
public:
    void insert(size_t index, const KeyType &item)
    {
        if(!contains(index))
        {
            data_[index]         = item;
            indexToPosition_[index]     = heapSize_;
            heap_[heapSize_] = index;
            ++heapSize_;
            swim(indexToPosition_[index]);
        }
    }
    void insert(size_t index, KeyType &&item)
    {
        if(!contains(index))
        {
            data_[index]         = std::move(item);
            indexToPosition_[index]     = heapSize_;
            heap_[heapSize_] = index;
            ++heapSize_;
            swim(indexToPosition_[index]);
        }
    }
    
    // When changing the item, the heap property should be maintaind by swim(indexToPriority_[index])
    void changeKey(size_t index, const KeyType &item)
    {
        data_[index] = item;
        swim(indexToPosition_[index]);
        sink(indexToPosition_[index]);
    }
    void changeKey(size_t index, KeyType &&item)
    {
        data_[index] = std::move(item);
        swim(indexToPosition_[index]);
        sink(indexToPosition_[index]);
    }
    void decreaseKey(size_t index, const KeyType &item)
    {
        data_[index] = item;
        swim(indexToPosition_[index]);
    }
    void decreaseKey(size_t index, KeyType &&item)
    {
        data_[index] = std::move(item);
        swim(indexToPosition_[index]);
    }
    void increaseKey(size_t index, const KeyType &item)
    {
        data_[index] = item;
        sink(indexToPosition_[index]);
    }
    void increaseKey(size_t index, KeyType &&item)
    {
        data_[index] = std::move(item);
        sink(indexToPosition_[index]);
    }
    
    void remove(size_t index)
    {
        exchange(index, --heapSize_);
        sink(indexToPosition_[index]);
        indexToPosition_[index] = -1;
    }
    
    //return index of Min
    size_t removeMin()
    {
        auto ret = heap_[0];
        exchange(0, --heapSize_);
        sink(0);
        indexToPosition_[ret] = -1;
        return ret;
    }
    
    KeyType minItem() const
    {
        return data_[heap_[0]];
    }
    
    size_t minIndex() const
    {
        return heap_[0];
    }
    
    bool empty() const
    {
        return heapSize_ == 0;
    }
    
    size_t size() const
    {
        return heapSize_;
    }
    
    bool contains(size_t index) const
    {
        return indexToPosition_[index] != -1;
    }
    
    KeyType getItem(size_t index) const
    {
        return data_[index];
    }
    
    friend ostream & operator<<(ostream &out, const IndexPriorityQueue<KeyType, cmp> &ipq)
    {
        for(const auto &i : ipq.prioriyToIndex_)
        {
            out << ipq.indexToItem_[i] << "  ";
        }
        return out;
    }
};


#endif
