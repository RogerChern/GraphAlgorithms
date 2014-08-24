//
//  Path.h
//  algs
//
//  Created by RogerChen on 14-8-14.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef algs_Path_h
#define algs_Path_h

#include "Graph.h"

class DepthFirstPath{
public:
    vector<size_t>       pathTo(size_t v);
    bool                 hasPathTo(size_t v);
public:
    DepthFirstPath(const Graph &g, size_t s);
private:
    vector<size_t>       pathTo_;
    vector<bool>         marked_;
private:
    void dfs(const Graph &, size_t);
};

#endif
