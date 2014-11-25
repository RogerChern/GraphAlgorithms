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
#include "IndexPriorityQueue.h"
#include <queue>
#include <cfloat>
using namespace std;

class EagerPrimMST{
private:
    static constexpr double                MAX = DBL_MAX;
    vector<Edge>                           mst_;
    vector<bool>                           marked_;
    vector<double>                         distTo_;
    IndexPriorityQueue<Edge>               crossingEdge_;

private:
    void visit(const EdgeWeightedGraph &ewg, size_t v)
    {
        marked_[v] = true;
        for(const auto &x : ewg.adj(v))
        {
            if(!marked_[x.other(v)] && x.weight() < distTo_[x.other(v)])
            {
                distTo_[x.other(v)] = x.weight();
                if(!crossingEdge_.contains(x.other(v)))
                {
                    crossingEdge_.insert(x.other(v), x);
                }
                else
                {
                    crossingEdge_.changeKey(x.other(v), x);
                }
            }
        }
    }
    
public:
    EagerPrimMST(const EdgeWeightedGraph &ewg):
        marked_(ewg.V(), false),
        distTo_(ewg.V(), +MAX), //the '+' is required
        crossingEdge_(ewg.V())
    {
        visit(ewg, 0);
        while(!crossingEdge_.empty())
        {
            auto index = crossingEdge_.minIndex();
            Edge e = crossingEdge_.getItem(crossingEdge_.removeMin());
            mst_.push_back(e);
            visit(ewg, index);
        }
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
