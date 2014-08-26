//
//  EagerPrimMST.h
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-25.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef MinimumSpanningTrees_EagerPrimMST_h
#define MinimumSpanningTrees_EagerPrimMST_h

#include "EdgeWeightedGraph.h"
#include <queue>
using namespace std;

class EagerPrimMST{
private:
    static const double                    MAX;
    vector<Edge>                           mst_;
    vector<bool>                           marked_;
    vector<double>                         distTo_;
    priority_queue<Edge, vector<Edge>, greater<Edge>>
                                           crossingEdge_;
private:
    void visit(const EdgeWeightedGraph &ewg, size_t v)
    {
        marked_[v] = true;
        for(const auto &x : ewg.adj(v))
        {
            if(!marked_[x.other(v)])
            {
                if(x.weight() < distTo_[x.other(v)])
                {
                    distTo_[x.other(v)] = x.weight();
                }
            }
        }
    }
public:
    EagerPrimMST(const EdgeWeightedGraph &ewg):
        marked_(ewg.V(), false),
        distTo_(ewg.V(), MAX)
    {
        
    }
public:
    vector<Edge> edges() const
    {
        return mst_;
    }
    
    double weight() const
    {
        double temp = 0.0f;
        for(const auto &x : mst_)
        {
            temp += x.weight();
        }
        return temp;
    }
};

#endif
