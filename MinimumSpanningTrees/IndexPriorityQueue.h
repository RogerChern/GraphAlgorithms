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
#include <unordered_map>
using namespace std;

template<typename KeyType, typename cmp = less<KeyType>>
class IndexPriorityQueue{
private:
    size_t                          heapSize_;         //size of already constructed heap
    vector<KeyType>                 indexToItem_;      //map index    -> KeyType      keys might be changed
    vector<size_t>                  priorityToIndex_;  //map priority -> index
    vector<size_t>                  indexToPriority_;  //map index    -> priority
    
private:
    void   exchange(size_t lprior, size_t rprior)
    {
        swap(priorityToIndex_[lprior], priorityToIndex_[rprior]);
        indexToPriority_[priorityToIndex_[lprior]] = lprior;
        indexToPriority_[priorityToIndex_[rprior]] = rprior;
    }
    
    bool   compare(size_t lprior, size_t rprior) const
    {
        return cmp()(indexToItem_[priorityToIndex_[lprior]], indexToItem_[priorityToIndex_[rprior]]);
    }
    
    size_t getParent(size_t child) const
    {
        return (child - 1) / 2 + 1;
    }
    
    size_t getLchild(size_t parent) const
    {
        return 2 * parent + 1;
    }
   
    size_t getLastNoneLeaf() const
    {
        return heapSize_ / 2 - 1;
    }
    
    void   sink(size_t index)
    {
        while(getLchild(index) < heapSize_)
        {
            auto lcld = getLchild(index);
            
            if(lcld + 1 < heapSize_ && compare(lcld + 1, lcld))
            {
                ++lcld;
            }
            if(compare(lcld, index))
            {
                exchange(lcld, index);
                index = lcld;
            }
            else
            {
                break;
            }
        }
    }

    void   swim(size_t v)
    {
        while(v > 0 && compare(v, getParent(v)))
        {
            auto parent = getParent(v);
            exchange(v, parent);
            v = parent;
        }
    }
    
public:
    explicit IndexPriorityQueue(size_t capacity):
        indexToItem_(capacity),
        heapSize_(0),
        priorityToIndex_(capacity),
        indexToPriority_(capacity, -1)
    {
        
    }
    
    IndexPriorityQueue(const vector<KeyType> &item):
        indexToItem_(item),
        heapSize_(item.size()),
        priorityToIndex_(item.size()),
        indexToPriority_(item.size(), -1)
    {
        for(auto i = 0; i < item.size(); ++i)
        {
            priorityToIndex_[i] = i;
            indexToPriority_[priorityToIndex_[i]] = i;
        }
        for(auto i = getLastNoneLeaf(); i != -1; --i)
        {
            sink(i);
        }
    }
    
public:
    void     insert(size_t index, const KeyType &item)
    {
        if(!contains(index))
        {
            ++heapSize_;
            indexToItem_[index]         = item;
            indexToPriority_[index]     = heapSize_;
            priorityToIndex_[heapSize_] = index;
            swim(index);
        }
    }
    void     insert(size_t index, KeyType &&item)
    {
        if(!contains(index))
        {
            ++heapSize_;
            indexToItem_[index]         = std::move(item);
            indexToPriority_[index]     = heapSize_;
            priorityToIndex_[heapSize_] = index;
            swim(index);
        }
    }
    
    // When changing the item, the heap property should be maintaind by swim(indexToPriority_[index])
    void     changeKey(size_t index, const KeyType &item)
    {
        indexToItem_[index] = item;
        swim(indexToPriority_[index]);
        sink(indexToPriority_[index]);
    }
    void     changeKey(size_t index, KeyType &&item)
    {
        indexToItem_[index] = std::move(item);
        swim(indexToPriority_[index]);
        sink(indexToPriority_[index]);
    }
    void     decreaseKey(size_t index, const KeyType &item)
    {
        indexToItem_[index] = item;
        swim(indexToPriority_[index]);
    }
    void     decreaseKey(size_t index, KeyType &&item)
    {
        indexToItem_[index] = std::move(item);
        swim(indexToPriority_[index]);
    }
    void     increaseKey(size_t index, const KeyType &item)
    {
        indexToItem_[index] = item;
        sink(indexToPriority_[index]);
    }
    void     increaseKey(size_t index, KeyType &&item)
    {
        indexToItem_[index] = std::move(item);
        sink(indexToPriority_[index]);
    }
    
    void     remove(size_t index)
    {
        exchange(index, --heapSize_);
        sink(index);
        indexToPriority_[index] = -1;
    }
    
    //return index of Min
    size_t   removeMin()
    {
        auto ret = priorityToIndex_[0];
        exchange(0, --heapSize_);
        sink(0);
        indexToPriority_[ret] = -1;
        return ret;
    }
    
    KeyType  minItem() const
    {
        return indexToItem_[priorityToIndex_[0]];
    }
    
    size_t   minIndex() const
    {
        return priorityToIndex_[0];
    }
    
    bool     empty() const
    {
        return heapSize_ == 0;
    }
    
    size_t   size() const
    {
        return heapSize_;
    }
    
    bool     contains(size_t index) const
    {
        return indexToPriority_[index] != -1;
    }
    
    KeyType  getItem(size_t index) const
    {
        return indexToItem_[index];
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
