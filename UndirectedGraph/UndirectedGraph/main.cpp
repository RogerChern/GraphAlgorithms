//
//  main.cpp
//  algs
//
//  Created by RogerChen on 14-8-14.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Graph.h"
#include "Search.h"
#include "Path.h"
#include "CC.h"
#include "SymbolGraph.h"
#include "BreathFirstPath.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Graph g(cin);
    cout << "Test instance of Graph.h\n";
    cout << "Vertexs: " << g.V() << ' ' << "Edges: " << g.E() << '\n';
    cout << g << endl;
    
    cout << "Test instance of Search.h\n";
    Search s(g, 0);
    cout << s << '\n';
    cout << endl;
    
    cout << "Test instance of DepthFirstPath.h\n";
    DepthFirstPath p(g, 0);
    auto pt = p.pathTo(6);
    cout << 0 << ' ';
    for(auto beg = pt.rbegin(), end = pt.rend(); beg != end; ++beg)
    {
        cout << *beg << ' ';
    }
    cout << '\n';
    cout << endl;
    
    cout << "Test instance of BreathFirstPath.h\n";
    BreathFirstPath b(g, 0);
    auto pt1 = b.pathTo(6);
    cout << 0 << ' ';
    for(auto beg = pt1.rbegin(), end = pt1.rend(); beg != end; ++beg)
    {
        cout << *beg << ' ';
    }
    cout << '\n';
    cout << endl;
    
    cout << "Test instance of CC.h\n";
    CC cc(g);
    cout << cc.count() << " components\n";
    for(int i = 0; i < cc.count(); ++i)
    {
        vector<size_t> temp = cc.componet(i);
        for(const auto &x : temp)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << endl;
    
//    cout << "Test instance of SymbolGraph.h\n";
//    string   fileName  = argv[1];
//    string   delim     = argv[2];
//    SymbolGraph sg(fileName, delim);
//    cout << sg << endl;

    return 0;
}

