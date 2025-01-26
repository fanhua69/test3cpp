//
//  main.cpp
//  testcpp2
//
//  Created by hua fan on 2023-05-28.
//

#include "headers.h"
#include "headers_2.h"


void ttt(char *p)
{
    cout << *p << endl;
}

int main(int argc, const char * argv[])
{
    system_clock::time_point t1 = system_clock::now();
    time_t tt1 = system_clock::to_time_t(t1);
    printThickLine();
    cout << "Start Time: " << std::ctime(&tt1);
    printThinLine();

    atomic_1_main();


    printThinLine();
    system_clock::time_point t2 = system_clock::now();
    time_t tt2 = system_clock::to_time_t(t2);
    cout << "End Time  :" << std::ctime(&tt2);
    printThickLine();

    return 0;
}
