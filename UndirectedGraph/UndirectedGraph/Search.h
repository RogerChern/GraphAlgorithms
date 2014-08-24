//
//  Search.h
//  algs
//
//  Created by RogerChen on 14-8-14.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#ifndef algs_Search_h
#define algs_Search_h

#include <vector>
#include <iostream>
#include "Graph.h"

class Search{
private:
    vector<bool>    marked_;
    size_t          count_;

public:
    bool    marked(size_t v) const;
    size_t  count() const;           //count records the number of reachable vertex from s

public:
    Search(const Graph &, size_t s);
    
private:
    void dfs(const Graph &, size_t s);
    
    friend ostream& operator<<(ostream &, const Search &);
};

ostream& operator<<(ostream &, const Search &);


#endif
