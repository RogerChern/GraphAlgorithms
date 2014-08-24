//
//  StringProcess.cpp
//  algs
//
//  Created by RogerChen on 14-8-15.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//

#include "StringProcess.h"


vector<string> split(const string &str, const string& delim)
{
    vector<string>  ret;
    size_t last     = 0;
	size_t index    = str.find_first_of(delim, last);
	while (index!=std::string::npos)
	{
		ret.push_back(str.substr(last, index-last));
		last=index+1;
		index=str.find_first_of(delim, last);
	}
	if (index-last>0)
	{
		ret.push_back(str.substr(last, index-last));
	}

    return ret;
}