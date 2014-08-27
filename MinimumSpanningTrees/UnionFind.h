//
//  UnionFind.h
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-27.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef MinimumSpanningTrees_UnionFind_h
#define MinimumSpanningTrees_UnionFind_h

#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
private:
    vector<size_t>    id_;
    size_t            count_;
public:
    UnionFind(size_t N):
        count_(N)
    {
        for(auto i = 0; i < N; ++i)
        {
            id_.push_back(i);
        }
    }
    
public:
    size_t find(size_t v) const
    {
        return id_[v];
    }
    
    bool   connected(size_t v, size_t w) const
    {
        return id_[v] == id_[w];
    }
    
    size_t count() const
    {
        return count_;
    }
    
    void   unite(size_t v, size_t w)
    {
        auto vid = id_[v];
        auto wid = id_[w];
        
        if(vid == wid)
        {
            return;
        }
        for(auto i = 0; i < id_.size(); ++i)
        {
            if(id_[i] == vid)
            {
                id_[i] = wid;
            }
        }
        --count_;
    }
};

#endif
