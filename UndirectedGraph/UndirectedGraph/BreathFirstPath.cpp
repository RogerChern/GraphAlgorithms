//
//  BreathFirstPath.cpp
//  algs
//
//  Created by RogerChen on 14-8-16.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "BreathFirstPath.h"

void BreathFirstPath::bfs(const Graph &g)
{
    while (!queue_.empty())
    {
        size_t s = queue_.front();
        queue_.pop();
        for(const auto &x : g.adj(s))
        {
            if(!marked_[x])
            {
                marked_[x] = true;
                pathTo_[x] = s;
                queue_.push(x);
            }
        }
    }
}

BreathFirstPath::BreathFirstPath(const Graph &g, size_t s):
    marked_(g.V(), false),
    pathTo_(g.V(), -1)
{
    marked_[s] = true;
    queue_.push(s);
    bfs(g);
}

bool BreathFirstPath::hasPathTo(size_t s) const
{
    return marked_[s];
}

const vector<size_t> BreathFirstPath::pathTo(size_t s) const
{
    vector<size_t> ret;
    while (pathTo_[s] != -1)
    {
        ret.push_back(s);
        s = pathTo_[s];
    }
    return ret;
}

