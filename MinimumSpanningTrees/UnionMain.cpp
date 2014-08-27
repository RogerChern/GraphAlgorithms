//
//  UnionMain.cpp
//  MinimumSpanningTrees
//
//  Created by RogerChen on 14-8-27.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "UnionFind.h"
#include <fstream>
using namespace std;


int main(int argc, char **argv)
{
    fstream fin("/Users/rogerchen/Desktop/data/tinyUF.txt");
    size_t temp;
    fin >> temp;
    
    UnionFind uf(temp);
    size_t x, y;
    while(fin >> x >> y)
    {
        if(uf.connected(x, y))
        {
            continue;
        }
        uf.unite(x, y);
        cout << x << "  " << y << '\n';
    }
    cout << uf.count() << endl;
    return 0;
}