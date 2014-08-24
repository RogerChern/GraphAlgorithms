//
//  Search.cpp
//  algs
//
//  Created by RogerChen on 14-8-14.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "Search.h"

ostream& operator<<(ostream &out, const Search &s)
{
    for(size_t i = 0; i < s.marked_.size(); ++i)
    {
        if(s.marked_[i])
        {
            cout << i << ' ';
        }
    }
    return out;
}

bool Search::marked(size_t v) const
{
    return marked_[v];
}

size_t Search::count() const
{
    return count_;
}

void Search::dfs(const Graph &g, size_t s)
{
    marked_[s] = true;
    ++count_;
    for(const auto &x : g.adj(s))
    {
        if(!marked_[x])
        {
            dfs(g, x);
        }
    }
}

Search::Search(const Graph &g, size_t s):
    count_(0),
    marked_(g.V(), 0)
{
    dfs(g, s);
}