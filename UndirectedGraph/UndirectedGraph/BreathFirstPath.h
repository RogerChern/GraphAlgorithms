//
//  BreathFirstPath.h
//  algs
//
//  Created by RogerChen on 14-8-16.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef algs_BreathFirstPath_h
#define algs_BreathFirstPath_h

#include <queue>
#include <vector>
#include "Graph.h"
using namespace std;

class BreathFirstPath{
private:
    queue<size_t>        queue_;
    vector<bool>         marked_;
    vector<size_t>       pathTo_;
private:
    void bfs(const Graph &);
public:
    BreathFirstPath(const Graph &, size_t);
public:
    const vector<size_t>       pathTo(size_t) const;
    bool                       hasPathTo(size_t) const;
    
};


#endif
