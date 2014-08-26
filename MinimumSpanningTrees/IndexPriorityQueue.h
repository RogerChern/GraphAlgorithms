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

template<typename Item, typename cmp = less<Item>>
class IndexPriorityQueue{
private:
    vector<Item>                    heap_;
    size_t                          heapSize_;
<<<<<<< HEAD
    vector<size_t>                  pq_;
    vector<size_t>                  qp_;
private:
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
            
            if(lcld + 1 < heapSize_ && cmp()(heap_[lcld+1], heap_[lcld]))
            {
                ++lcld;
            }
            if(cmp()(heap_[lcld], heap_[index]))
            {
                swap(heap_[lcld], heap_[index]);
                index = lcld;
=======
private:
    void sink(size_t v)
    {
        while(v < heapSize_ / 2)
        {
            auto w = 2 * v + 1;
            if(w < heapSize_ - 1 && cmp()(heap_[w+1], heap_[w]))
            {
                ++w;
            }
            if(cmp()(heap_[w], heap_[v]))
            {
                swap(heap_[w], heap_[v]);
                v = w;
>>>>>>> FETCH_HEAD
            }
            else
            {
                break;
            }
        }
    }
<<<<<<< HEAD
        
    void   swim(size_t v)
    {
        while(v > 0 && cmp()(v, getParent(v)))
        {
            auto parent = getParent(v);
            swap(heap_[v], heap_[parent]);
            v = parent;
        }
    }
    
public: //for test only     should be undocumented
        //for unknown reason the cmp() version of is_heap does not work
    bool   isMaxPQ() const
    {
        return is_heap(heap_.begin(), heap_.end());
    }
    
    bool   isMinPQ() const
    {
        return is_heap(heap_.begin(), heap_.end(), greater<Item>());
    }
    
=======
    
    void swim(size_t v)
    {
        while(v > 0 && (cmp()(v, (v - 1) / 2) + 1))
        {
                swap(heap_[v], heap_[(v - 1) / 2 + 1]);
                v = (v - 1) / 2 + 1;
        }
    }
    
>>>>>>> FETCH_HEAD
public:
    bool test() const
    {
        return !is_heap(heap_.begin(), heap_.end(), cmp());
    }
    
public:
    explicit IndexPriorityQueue(size_t capacity):
<<<<<<< HEAD
        heap_(capacity),
        heapSize_(capacity),
        pq_(capacity),
        qp_(capacity, -1)
    {
        
    }
    
    IndexPriorityQueue(const vector<Item> &item):
        heap_(item),
        heapSize_(item.size()),
        pq_(item.size()),
        qp_(item.size(), -1)
    {
        for(auto i = getLastNoneLeaf(); i != -1; --i)
=======
    heap_(capacity),
    heapSize_(0)
    {
        
    }
    IndexPriorityQueue(const vector<Item> &item):
        heap_(item),
        heapSize_(item.size())
    {
        for(auto i = heapSize_/2 - 1; i != -1; --i)
>>>>>>> FETCH_HEAD
        {
            sink(i);
        }
    }
<<<<<<< HEAD
    
public:
    void     insert(size_t index, const double &item)
    {
        if(!contains(index))
        {
            ++heapSize_;
            qp_[index]     = heapSize_;
            pq_[heapSize_] = index;
            heap_[index]   = item;
            swim(index);
        }
=======
public:
    void     insert(size_t index, const double &item)
    {
        
>>>>>>> FETCH_HEAD
    }
    void     change(size_t index, const double &item);
    void     remove(size_t index);
    void     remove(const double &item);
    size_t   removeMin();
    
    double   min() const;
    size_t   minIndex() const;
<<<<<<< HEAD
    
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
        return qp_[index] != -1;
    }
=======
    bool     empty() const;
    size_t   size() const;
    bool     contain(size_t index) const;
>>>>>>> FETCH_HEAD
    
    friend ostream & operator<<(ostream &out, const IndexPriorityQueue<Item, cmp> &ipq)
    {
        for(const auto &i : ipq.heap_)
        {
            out << i << "  ";
        }
        return out;
    }
};


#endif
