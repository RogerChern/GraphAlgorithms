//
//  SymbolDiGraph.h
//  DirectedGraph
//
//  Created by RogerChen on 14-8-22.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef DirectedGraph_SymbolDiGraph_h
#define DirectedGraph_SymbolDiGraph_h
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "DirectedGraph.h"
#include "DirectedAuxiliary.h"
using namespace std;

class SymbolDiGraph{
private:
    vector<string>          indexToName_;
    map<string, size_t>     nameToIndex_;
    DirectedGraph           g_;
public:
    SymbolDiGraph(const string &fileName, const string &delim);
public:
    const DirectedGraph &   G() const;
    bool                    contains(const string &) const;
    size_t                  index(const string &) const;
    string                  name(size_t) const;
    
    friend ostream & operator<<(ostream &, const SymbolDiGraph &);
};

ostream & operator<<(ostream &, const SymbolDiGraph &);



#endif
