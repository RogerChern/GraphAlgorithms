//
//  TopologicalSort.h
//  ShortestPaths
//
//  Created by RogerChen on 14-8-30.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef ShortestPaths_TopologicalSort_h
#define ShortestPaths_TopologicalSort_h

#include "EdgeWeighedDiGraph.h"
#include <stack>
#include <utility>
using namespace std;

class TopologicalSort{
private:
    vector<bool>                    marked_;
    stack<DirectedWeighedEdge>      reversePostOrder_;
private:
    void dfs(const EdgeWeightedDiGraph &ewdg, size_t vertex)
    {
        for(const auto &e : ewdg.adj(vertex))
        {
            if(!marked_[e.to()])
            {
                marked_[e.to()] = true;
                dfs(ewdg, e.to());
            }
            reversePostOrder_.push(e);
        }
    }
public:
    TopologicalSort(const EdgeWeightedDiGraph &ewdg):
        marked_(ewdg.V(), false)
    {
        for(auto i = 0; i < ewdg.V(); i++)
        {
            if(!marked_[i])
            {
                marked_[i] = true;
                dfs(ewdg, i);
            }
        }
    }
public:
    vector<DirectedWeighedEdge> reversePostOrder() const
    {
        stack<DirectedWeighedEdge>  temp(reversePostOrder_);
        vector<DirectedWeighedEdge> ret;
        while(!temp.empty())
        {
            ret.push_back(std::move(temp.top()));
            temp.pop();
        }
        return ret;
    }
};
#endif
