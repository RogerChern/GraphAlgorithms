//
//  SymbolDiGraph.cpp
//  DirectedGraph
//
//  Created by RogerChen on 14-8-22.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "SymbolDiGraph.h"

ostream & operator<<(ostream &out, const SymbolDiGraph &sdg)
{
    for(int i = 0; i < sdg.G().V(); ++i)
    {
        out << sdg.indexToName_[i] << ": \n";
        for(const auto &x : sdg.G().adj(i))
        {
            out << "    " << sdg.indexToName_[x] << '\n';
        }
    }
    return out;
}

bool SymbolDiGraph::contains(const string & name) const
{
    return nameToIndex_.find(name) != nameToIndex_.end();
}

const DirectedGraph & SymbolDiGraph::G() const
{
    return g_;
}

string SymbolDiGraph::name(size_t index) const
{
    return indexToName_[index];
}

size_t SymbolDiGraph::index(const string &name) const
{
    if(!contains(name))
    {
        return -1;
    }
    return nameToIndex_.at(name);
}

SymbolDiGraph::SymbolDiGraph(const string &fileName, const string &delim)
{
    fstream in(fileName);
    vector<string> tempVec;
    string         tempStr;
    while(getline(in, tempStr))
    {
        tempVec = split(tempStr, delim);
        for(const auto &x : tempVec)
        {
            if(nameToIndex_.find(x) == nameToIndex_.end())//there should be "==" than "!="
            {
                nameToIndex_[x] = nameToIndex_.size();
            }
        }
    }
    in.close();
    
    indexToName_ = std::move(vector<string>(nameToIndex_.size()));
    for(const auto &x : nameToIndex_)
    {
        indexToName_[x.second] = x.first;
    }
    
    g_ = DirectedGraph(static_cast<unsigned int>(nameToIndex_.size()));
    in = fstream(fileName);
    
    while(getline(in, tempStr))
    {
        tempVec = split(tempStr, delim);
        for(size_t i = 1; i < tempVec.size(); ++i)
        {
            g_.addEdge(nameToIndex_[tempVec[0]], nameToIndex_[tempVec[i]]);
        }
    }
    
}