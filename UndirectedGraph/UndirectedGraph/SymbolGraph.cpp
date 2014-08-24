//
//  SymbolGraph.cpp
//  algs
//
//  Created by RogerChen on 14-8-15.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "SymbolGraph.h"
#include "StringProcess.h"
using namespace std;

ostream & operator<<(ostream &out, const SymbolGraph &sg)
{
    Graph g = sg.getGraph();
    for(size_t i = 0; i < g.V(); ++i)
    {
        cout << sg.name(i) << ": ";
        for(const auto &j : g.adj(i))
        {
            cout << sg.name(j) << ' ';
        }
        cout << endl;
    }
    return out;
}

SymbolGraph::SymbolGraph(const string &fileName, const string &delim):
graph_(0)
{
    string line;
    vector<string> str_vec;
    fstream in(fileName);
    
    while(getline(in, line))
    {
        str_vec = split(line, delim);
        for(const auto &x : str_vec)
        {
            if(symbol_table_.find(x) == symbol_table_.end())
            {
                symbol_table_.emplace(x, symbol_table_.size());
            }
        }
    }
    
    
    keys_ = vector<string>(symbol_table_.size());
    for(const auto &x : symbol_table_)
    {
        keys_[x.second] = x.first;
    }
    
    
    graph_ = Graph(symbol_table_.size());
    in     = fstream(fileName);

    while (getline(in, line))
    {
        str_vec   = split(line, delim);
        size_t v  = symbol_table_[str_vec[0]];
        for(int i = 1; i < str_vec.size(); ++i)
        {
            size_t w = symbol_table_[str_vec[i]];
            graph_.addEdge(v, w);
            graph_.addEdge(w, v);
        }
    }
}

bool SymbolGraph::contains(const string &key) const
{
    return symbol_table_.find(key) != symbol_table_.end();
}

const Graph & SymbolGraph::getGraph() const
{
    return graph_;
}

size_t SymbolGraph::index(const string &key) const  //[] conflicts with constness
{
    return symbol_table_.at(key);
}

string SymbolGraph::name(size_t v) const
{
    return keys_[v];
}

size_t SymbolGraph::V() const
{
    return graph_.V();
}

size_t SymbolGraph::E() const
{
    return graph_.E();
}



