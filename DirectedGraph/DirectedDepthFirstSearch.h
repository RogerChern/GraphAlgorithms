//
//  DirectedDepthFirstSearch.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-19.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_DirectedDepthFirstSearch_h
#define DirectedGraph_DirectedDepthFirstSearch_h

#include "DirectedSearchGraph.h"

class DirectedDepthFirstSearch: public DirectedSearchGraph{
public:
    DirectedDepthFirstSearch(const DirectedGraph &dg, size_t s):
        DirectedSearchGraph(dg, s)
    {
        marked_[s] = true;
        dfs(dg, s);
    }
    DirectedDepthFirstSearch(const DirectedGraph &dg, vector<size_t> vec):
        DirectedSearchGraph(dg, vec)
    {
        for(const auto &x: vec)
        {
            if(!marked_[x])
            {
                marked_[x] = true;
                dfs(dg, x);
            }
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
                dfs(dg, x);
            }
        }
    }
    
};

#endif
