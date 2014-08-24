//
//  CC.cpp
//  algs
//
//  Created by RogerChen on 14-8-15.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "CC.h"

CC::CC(const Graph &g):
    marked_(g.V(), false),
    id_(g.V(), -1),
    count_(0)
{
    for(size_t i = 0; i < g.V(); ++i)
    {
        if(!marked_[i])
        {
            dfs(g, i);
            ++count_;
        }
    }
}

void CC::dfs(const Graph &g, size_t v)
{
    marked_[v] = true;
    id_[v]     = count_;
    for(const auto &x: g.adj(v))
    {
        if(!marked_[x])
            dfs(g, x);
    }
}

bool CC::connected(size_t v, size_t w)
{
    return id_[v] == id_[w];
}

size_t CC::count()
{
    return count_;
}

size_t CC::id(size_t v)
{
    return id_[v];
}

vector<size_t> CC::componet(size_t idnumber){
    vector<size_t> ret;
    for (size_t i = 0; i < id_.size(); ++i)
    {
        if (id(i) == idnumber)
        {
            ret.push_back(i);
        }
    }
    return ret;
}