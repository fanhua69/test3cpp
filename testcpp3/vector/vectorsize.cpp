//
//  vectorsize.cpp
//  testcpp2
//
//  Created by hua fan on 2023-09-01.
//

#include <stdio.h>
#include "headers.h"

extern int g_exerterna ;

void vectorMain()
{
    int row = 5;
    int col = 5;

    //vector<vector<pair<int,int>>> a(row, vector<pair<int,int>>(col, {1,2}));

    vector<int> a(10,-1);

    printme(a);

    cout << "extern a:" << g_exerterna << endl;
}
