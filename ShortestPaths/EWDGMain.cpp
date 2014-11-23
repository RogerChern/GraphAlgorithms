//
//  EWDGMain.cpp
//  ShortestPaths
//
//  Created by RogerChen on 14-8-27.
//  Copyright (c) 2014年 RogerChen. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int i;
    char buffer [33];
    printf ("Enter a number: ");
    scanf ("%d",&i);
    itoa (i,buffer,10);
    printf ("decimal: %s\n",buffer);
    itoa (i,buffer,16);
    printf ("hexadecimal: %s\n",buffer);
    itoa (i,buffer,2);
    printf ("binary: %s\n",buffer);
    return 0;
}
