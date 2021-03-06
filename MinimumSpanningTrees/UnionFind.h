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
    vector<size_t>    id_;     //groupId array
    vector<size_t>    size_;   //groupSize array
    size_t            ngroups_;  //number of groups
public:
    UnionFind(size_t N):
        ngroups_(N)
    {
        for(auto i = 0; i < N; ++i)
        {
            id_.push_back(i);
            size_.push_back(1);
        }
    }
    
public:
    size_t find(size_t v)
    {
        auto temp = v;
        while(v != id_[v])
        {
            v = id_[v];
        }
        while(temp != id_[temp])
        {
            id_[temp]   = v;
            size_[v]   += size_[temp];
            temp        = id_[temp];
        }
        return v;
    }
    
    bool connected(size_t v, size_t w)
    {
        return find(v) == find(w);
    }
    
    size_t count() const
    {
        return ngroups_;
    }
    
    void unite(size_t v, size_t w)
    {
        auto vid = find(v);
        auto wid = find(w);
        
        if(vid == wid)
        {
            return;
        }
        
        if(size_[vid] < size_[wid])
        {
            id_[vid]    = wid;
            size_[wid] += size_[vid];
        }
        else
        {
            id_[wid]    = vid;
            size_[vid] += size_[wid];
        }
        --ngroups_;
    }
};

#endif
