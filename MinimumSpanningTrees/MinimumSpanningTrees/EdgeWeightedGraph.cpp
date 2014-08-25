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