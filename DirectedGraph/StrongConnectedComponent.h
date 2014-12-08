//
//  StrongConnectedComponent.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-22.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_StrongConnectedComponent_h
#define DirectedGraph_StrongConnectedComponent_h

#include "DirectedGraph.h"
#include "DirectedDepthFirstOrder.h"
#include <vector>
#include <stack>
using namespace std;

class StrongConnectedComponent{
private:
    vector<size_t>      marked_;
    vector<size_t>      id_;
    size_t              count_;
public:
    StrongConnectedComponent(const DirectedGraph &dg):
        marked_(dg.V(), false),
        id_(dg.V(), -1),
        count_(0)
    {
        DirectedDepthFirstOrder ddfo(dg.reverse());
        stack<size_t> order = std::move(ddfo.reversePostOrder());
        while(!order.empty())
        {
            if(!marked_[order.top()])
            {
                marked_[order.top()];
                id_[order.top()];
                dfs(dg, order.top());
                ++count_;
            }
            order.pop();
        }
    }
private:
    void dfs(const DirectedGraph &dg, size_t v)
    {
        for(const auto &x : dg.adj(v))
        {
            if(!marked_[x])
            {
                marked_[x] = true;
                id_[x]     = count_;
                dfs(dg, x);
            }
        }
    }
public:
    bool connected(size_t i, size_t v) const
    {
        return id_[i] == id_[v];
    }
    
    size_t count() const
    {
        return count_;
    }
    
    size_t id(size_t v) const
    {
        return id_[v];
    }
};

#endif
