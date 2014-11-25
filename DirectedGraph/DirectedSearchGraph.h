//
//  DirectedSearchGraph.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-19.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_DirectedSearchGraph_h
#define DirectedGraph_DirectedSearchGraph_h

#include "DirectedGraph.h"
#include <vector>
#include <cctype>
#include <queue>
using namespace std;

class DirectedSearchGraph{
protected:
    vector<size_t>        marked_;
public:
    DirectedSearchGraph(const DirectedGraph &dg, size_t s):
        marked_(dg.V(), false)
    {
        
    }
    DirectedSearchGraph(const DirectedGraph &dg, vector<size_t> s):
        marked_(dg.V(), false)
    {
        
    }
public:
    bool reachable(size_t v) const
    {
        return marked_[v];
    }
};

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
        for(auto &&i : vec)
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
            for(auto &&x : dg.adj(temp))
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
        for(auto &&x : dg.adj(v))
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