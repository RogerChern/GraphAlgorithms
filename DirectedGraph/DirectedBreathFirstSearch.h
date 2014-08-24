//
//  DirectedBreathFirstSearch.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-19.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_DirectedBreathFirstSearch_h
#define DirectedGraph_DirectedBreathFirstSearch_h

#include "DirectedSearchGraph.h"
#include <queue>
using namespace std;

class DirectedBreathFirstSearch: public DirectedSearchGraph{
private:
    queue<size_t>   queue_;
public:
    DirectedBreathFirstSearch(const DirectedGraph &dg, size_t s):
        DirectedSearchGraph(dg, s)
    {
        marked_[s] = true;
        queue_.push(s);
        bfs(dg);
    }
    DirectedBreathFirstSearch(const DirectedGraph &dg, vector<size_t> vec):
        DirectedSearchGraph(dg, vec)
    {
        for(const auto &i : vec)
        {
            if(!marked_[i])
            {
                marked_[i] = true;
                queue_.push(i);
                bfs(dg);
            }
        }
    }
private:
    void bfs(const DirectedGraph &dg)
    {
        size_t temp;
        while(!queue_.empty())
        {
            temp = queue_.front();
            queue_.pop();
            for(const auto &x : dg.adj(temp))
            {
                if(!marked_[x])
                {
                    marked_[x] = true;
                    queue_.push(x);
                }
            }
        }
    }

};

#endif
