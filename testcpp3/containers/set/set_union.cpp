//
//  set_union.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-13.
//

#include <stdio.h>
#include "headers.h"
#include <algorithm>
#include <iterator>


void set_union_test()
{
    vector<int> a {3,2,5};
    vector<int> b {9,7,8};

    vector<int> c;
    c.resize(a.size() + b.size());
    std::set_union(a.begin(),a.end(), b.begin(), b.end(), c.begin());


    vector<int> d;
    std::copy(a.begin(), a.end(), std::back_inserter(d));
    std::copy(b.begin(), b.end(), std::back_inserter(d));

    ps p(3);
    print(d, p);


    vector<int> e;
    e.resize(a.size() + b.size());
    std::copy(a.begin(), a.end(), e.begin());
    std::copy(b.begin(), b.end(), e.begin());

    ps p2(3);
    print(e,p2);

    vector<int> f;
    f.insert(f.begin(), a.begin(), a.end());
    f.insert(f.begin(), b.begin(), b.end());

    ps p3(3);
    print(f,p3);

}
