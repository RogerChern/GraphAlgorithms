//
//  LazyPrimMST.h
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-25.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef MinimumSpanningTrees_LazyPrimMST_h
#define MinimumSpanningTrees_LazyPrimMST_h

#include "EdgeWeightedGraph.h"
#include <queue>
#include <vector>
#include <utility>
#include <functional>
using namespace std;

class LazyPrimMST{
private:
    priority_queue<Edge, vector<Edge>, greater<Edge>>
                               crossEdge_;
    vector<bool>               marked_;
    vector<Edge>               mst_;
private:
    void visit(const EdgeWeightedGraph &ewg, size_t v)//push all(ineligible included) edges into heap
    {
        marked_[v] = true;
        for(const auto &x : ewg.adj(v))
        {
            if(!marked_[x.other(v)])
            {
                crossEdge_.push(x);
            }
        }
    }
    
public:
    LazyPrimMST(const EdgeWeightedGraph &ewg):
    marked_(ewg.V(), false)
    {
        visit(ewg, 0);
        
        Edge temp;
        size_t x, y;
        while(!crossEdge_.empty())//check all edges(include inenligible)
        {
            temp = std::move(crossEdge_.top());
            crossEdge_.pop();
            
            x = temp.either();
            y = temp.other(x);
            if(marked_[x] && marked_[y])//it indicates the edge examed was not an optimal
            {
                continue;
            }
            
            mst_.push_back(temp);
            if(!marked_[x])
            {
                visit(ewg, x);
            }
            else
            {
                visit(ewg, y);
            }
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
