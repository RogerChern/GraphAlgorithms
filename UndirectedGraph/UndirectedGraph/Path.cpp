//
//  Path.cpp
//  algs
//
//  Created by RogerChen on 14-8-14.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "Path.h"
#include <vector>

DepthFirstPath::DepthFirstPath(const Graph &g, size_t s):
    marked_(g.V(), 0),
    pathTo_(g.V(), -1)
{
    dfs(g, s);
}

void DepthFirstPath::dfs(const Graph &g, size_t s)
{
    marked_[s] = true;
    for(const auto &x : g.adj(s))
    {
        if(!marked_[x])
        {
            pathTo_[x] = s;
            dfs(g, x);
        }
    }
}

bool DepthFirstPath::hasPathTo(size_t v)
{
    return pathTo_[v] != -1;
}

vector<size_t> DepthFirstPath::pathTo(size_t s)
{
    vector<size_t> ret;
    while(pathTo_[s] != -1)
    {
        ret.push_back(s);
        s = pathTo_[s];
    }
    return ret;
}