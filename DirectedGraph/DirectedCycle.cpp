//
//  DirectedCycle.cpp
//  DirectedGraph
//
//  Created by RogerChen on 14-8-18.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "DirectedCycle.h"

void DirectedCycle::dfs(const DirectedGraph &dg, size_t s)
{
    for(const auto &iter : dg.adj(s))
    {
        if(hasCycle_)
        {
            onStacked_[iter] = false;
            return;
        }
        if(!marked_[iter])
        {
            marked_[iter]    = true;
            onStacked_[iter] = true;
            pathTo_[iter]    = s;
            dfs(dg, iter);
        }
        else if(onStacked_[iter])
        {
            hasCycle_ = true;
            cycle_.push_back(iter);
            cycle_.push_back(s);
            while(pathTo_[s] != iter)
            {
                s = pathTo_[s];
                cycle_.push_back(s);
            }
            cycle_.push_back(iter);
            return;
        }
    }
    onStacked_[s] = false;
}

DirectedCycle::DirectedCycle(const DirectedGraph &dg):
    pathTo_(dg.V(), -1),
    marked_(dg.V(), false),
    onStacked_(dg.V(), false),
    hasCycle_(false)
{
    for(auto i = 0; i < dg.V(); ++i)
    {
        if(!marked_[i])
        {
            marked_[i]     = true;
            onStacked_[i]  = true;
            dfs(dg, i);
        }
    }
}

vector<size_t> DirectedCycle::cycle() const
{
    return cycle_;
}

bool DirectedCycle::hasCycle() const
{
    return hasCycle_;
}