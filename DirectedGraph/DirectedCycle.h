//
//  DirectedCycle.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-18.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_DirectedCycle_h
#define DirectedGraph_DirectedCycle_h

#include "DirectedGraph.h"
#include <vector>
#include <utility>
using namespace std;

class DirectedCycle{
private:
    vector<bool>           marked_;
    vector<bool>           onStacked_;
    vector<size_t>         pathTo_;
    vector<size_t>         cycle_;
    bool                   hasCycle_;
private:
    void dfs(const DirectedGraph &, size_t);
public:
    DirectedCycle(const DirectedGraph &);
public:
    bool                   hasCycle() const;
    vector<size_t>         cycle() const;
};

#endif
