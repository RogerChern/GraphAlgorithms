//
//  KruskalMST.h
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-27.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef MinimumSpanningTrees_KruskalMST_h
#define MinimumSpanningTrees_KruskalMST_h

#include "UnionFind.h"
#include "EdgeWeightedGraph.h"
#include <functional>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

class KruscalMST{
private:
    vector<Edge>                                           mst_;
    priority_queue<Edge, vector<Edge>, greater<Edge>>      pq_;
    UnionFind                                              uf_;
    
public:
    KruscalMST(const EdgeWeightedGraph &ewg):
        pq_(greater<Edge>(), std::move(ewg.edges())),
        uf_(ewg.V())
    {
        Edge e;
        while(!pq_.empty() && mst_.size() < ewg.V())
        {
            e = pq_.top();
            pq_.pop();
            
            auto v = e.either();
            auto w = e.other(v);
            if(uf_.connected(v, w))
            {
                continue;
            }
            uf_.unite(v, w);
            mst_.push_back(e);
        }
    }
    
public:
    vector<Edge> edges() const
    {
        return mst_;
    }
    
    double weight() const
    {
        double ret = 0.0f;
        for(const auto &x : mst_)
        {
            ret += x.weight();
        }
        return ret;
    }
};
#endif
