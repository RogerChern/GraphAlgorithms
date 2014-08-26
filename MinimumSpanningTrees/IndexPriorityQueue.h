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
            }
            else
            {
                break;
            }
        }
    }
    
    void swim(size_t v)
    {
        while(v > 0 && (cmp()(v, (v - 1) / 2) + 1))
        {
                swap(heap_[v], heap_[(v - 1) / 2 + 1]);
                v = (v - 1) / 2 + 1;
        }
    }
    
public:
    bool test() const
    {
        return !is_heap(heap_.begin(), heap_.end(), cmp());
    }
    
public:
    explicit IndexPriorityQueue(size_t capacity):
    heap_(capacity),
    heapSize_(0)
    {
        
    }
    IndexPriorityQueue(const vector<Item> &item):
        heap_(item),
        heapSize_(item.size())
    {
        for(auto i = heapSize_/2 - 1; i != -1; --i)
        {
            sink(i);
        }
    }
public:
    void     insert(size_t index, const double &item)
    {
        
    }
    void     change(size_t index, const double &item);
    void     remove(size_t index);
    void     remove(const double &item);
    size_t   removeMin();
    
    double   min() const;
    size_t   minIndex() const;
    bool     empty() const;
    size_t   size() const;
    bool     contain(size_t index) const;
    
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
