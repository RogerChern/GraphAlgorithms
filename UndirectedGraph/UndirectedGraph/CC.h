//
//  CC.h
//  algs
//
//  Created by RogerChen on 14-8-15.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef algs_CC_h
#define algs_CC_h

#include "Graph.h"
#include <vector>
using namespace std;

class CC{
private:
    vector<bool>        marked_;
    vector<size_t>      id_;
    size_t              count_;
private:
    void dfs(const Graph &, size_t);
public:
    CC(const Graph &);
public:
    bool                connected(size_t v, size_t w);
    size_t              count();
    size_t              id(size_t v);
    vector<size_t>      componet(size_t id);
};


#endif
