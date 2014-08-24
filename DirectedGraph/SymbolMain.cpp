//
//  SymbolMain.cpp
//  DirectedGraph
//
//  Created by RogerChen on 14-8-24.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include <iostream>
#include "SymbolDiGraph.h"
using namespace std;

int main(int argc, char ** argv)
{
      SymbolDiGraph sdg(argv[1], argv[2]);
      cout << sdg << endl;
}