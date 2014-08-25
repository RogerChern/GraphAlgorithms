//
//  EdgeWeightedGraph.cpp
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-25.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "EdgeWeightedGraph.h"

bool operator<(const Edge &lhs, const Edge &rhs)
{
    return lhs.weight() < rhs.weight();
}

ostream & operator<<(ostream &out, const EdgeWeightedGraph &ewg)
{
    for(auto i = 0; i < ewg.V_; ++i)
    {
        out << i << ": \n";
        for(const auto &x : ewg.adjList_[i])
        {
            out << "    " << x.other(i) << ' ' << x.weight() << '\n';
        }
    }
    return out;
}