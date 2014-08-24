//
//  SymbolGraph.h
//  algs
//
//  Created by RogerChen on 14-8-15.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef algs_SymbolGraph_h
#define algs_SymbolGraph_h

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "Graph.h"
using namespace std;

class SymbolGraph{
private:
    Graph                             graph_;
    vector<string>                    keys_;
    map<string, size_t>               symbol_table_;
public:
    SymbolGraph(const string &, const string &);
public:
    bool                              contains(const string &key) const;
    size_t                            index(const string &key) const;
    string                            name(size_t v) const;
    const Graph &                     getGraph() const;
    size_t                            V() const;
    size_t                            E() const;
    
    friend ostream & operator<<(ostream &, const SymbolGraph &);
};
ostream & operator<<(ostream &, const SymbolGraph &);

#endif
