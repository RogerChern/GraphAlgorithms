//
//  DirectedDepthFirstOrder.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-22.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_DirectedDepthFirstOrder_h
#define DirectedGraph_DirectedDepthFirstOrder_h

#include "DirectedGraph.h"
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class DirectedDepthFirstOrder{
private:
    queue<size_t>      pre_;
    queue<size_t>      post_;
    stack<size_t>      rpost_;
    vector<size_t>     marked_;
public:
    DirectedDepthFirstOrder(const DirectedGraph &dg):
        marked_(dg.V(), false)
    {
        for(auto i = 0; i < dg.V(); ++i)
        {
            if(!marked_[i])
            {
                marked_[i] = true;
                dfs(dg, i);
            }
        }
    }
    
    queue<size_t> preOrder() const
    {
        return pre_;
    }
    
    queue<size_t> postOrder() const
    {
        return post_;
    }
    
    stack<size_t> reversePostOrder() const
    {
        return rpost_;
    }
    
private:
    void dfs(const DirectedGraph &dg, size_t v)
    {
        pre_.push(v);
        for(auto &&x : dg.adj(v))
        {
            if(!marked_[x])
            {
                marked_[x] = true;
                dfs(dg, x);
            }
        }
        post_.push(v);
        rpost_.push(v);
    }
};

#endif
