//
//  DirectedFindPath.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-19.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_DirectedFindPath_h
#define DirectedGraph_DirectedFindPath_h

#include "DirectedGraph.h"
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class DirectedFindPath{
protected:
    vector<size_t>       pathTo_;
    vector<bool>         marked_;
public:
    DirectedFindPath(const DirectedGraph &dg, size_t s):
    pathTo_(dg.V(), -1),
    marked_(dg.V(), false)
    {
        
    }
public:
    vector<size_t> pathTo(size_t v) const
    {
        vector<size_t> ret;
        while(pathTo_[v] != -1)
        {
            ret.push_back(v);
            v = pathTo_[v];
        }
        ret.push_back(v);
        return std::move(ret);
    }
};

class DirectedDepthFirstPath: public DirectedFindPath{
private:
    void dfs(const DirectedGraph &dg, size_t s)
    {
        for(const auto &x : dg.adj(s))
        {
            if(!marked_[x])
            {
                marked_[x] = true;
                pathTo_[x] = s;
                dfs(dg, x);
            }
        }
    }
public:
    DirectedDepthFirstPath(const DirectedGraph &dg, size_t s):
    DirectedFindPath(dg, s)
    {
        marked_[s] = true;
        dfs(dg, s);
    }
};

class DirectedBreathFirstPath: public DirectedFindPath{
private:
    queue<size_t> queue_;
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
                    pathTo_[x] = temp;
                    queue_.push(x);
                }
            }
        }
    }
public:
    DirectedBreathFirstPath(const DirectedGraph &dg, size_t s):
    DirectedFindPath(dg, s)
    {
        marked_[s] = true;
        queue_.push(s);
        bfs(dg);
    }
};



#endif
