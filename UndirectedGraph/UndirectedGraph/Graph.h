//
//  Graph.h
//  algs
//
//  Created by RogerChen on 14-8-14.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef algs_Graph_h
#define algs_Graph_h

#include<vector>
#include<memory>
#include<iostream>
using namespace std;

class Graph{
private:
    shared_ptr<vector<vector<size_t>>>   adj_;
    size_t                               V_;
    size_t                               E_;
public://interface
    size_t                               V() const;
    size_t                               E() const;
    vector<size_t> &                     adj(size_t);
    const vector<size_t> &               adj(size_t) const;
    void                                 addEdge(size_t ,size_t);
public://constructor
    Graph() = default;
    Graph(size_t V);
    Graph(istream &);
    
    friend ostream & operator<<(ostream &, const Graph &);
};

ostream & operator<<(ostream &out, const Graph &g);
#endif
