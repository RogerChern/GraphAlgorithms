//
//  DirectedAuxiliary.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-19.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_DirectedAuxiliary_h
#define DirectedGraph_DirectedAuxiliary_h
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <cctype>
using namespace std;

ostream & operator<<(ostream &, const vector<size_t> &);

vector<string> split(const string &raw, const string &delim);

#endif
