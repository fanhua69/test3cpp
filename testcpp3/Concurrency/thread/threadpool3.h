//
//  threadpool3.h
//  testcpp3
//
//  Created by hua fan on 2024-03-10.
//

#ifndef threadpool3_h
#define threadpool3_h

#include <queue>


class ThreadPool
{

    public:

        std::queue<std::functional<void()> queue_;

}

#endif /* threadpool3_h */
