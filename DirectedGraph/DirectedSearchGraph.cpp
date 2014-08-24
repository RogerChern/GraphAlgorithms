//
//  DirectedSearchGraph.cpp
//  DirectedGraph
//
//  Created by RogerChen on 14-8-19.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "DirectedSearchGraph.h"

DirectedSearchGraph::DirectedSearchGraph(const DirectedGraph &dg, size_t s):
    marked_(dg.V(), false)
{
    
}

DirectedSearchGraph::DirectedSearchGraph(const DirectedGraph &dg, vector<size_t> s):
    marked_(dg.V(), false)
{
    
}

bool DirectedSearchGraph::reachable(size_t v) const
{
    return marked_[v];
}