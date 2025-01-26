//
//  shared_lock.cpp
//  testcpp3
//
//  Created by hua fan on 2024-01-01.
//

#include <stdio.h>
#include <mutex>
#include <thread>
#include <shared_mutex>

#include "headers.h"
#include <chrono>


std::shared_mutex mutex_;  // since c++17
std::mutex mutex_screen;
std::condition_variable cond;
std::mutex mutex_data;

std::atomic_int g_rw = 1;

int value_ = 2;
std::atomic<int> thread_read = 1;

unsigned int read(int t)
{
    std::shared_lock<std::shared_mutex> lock(mutex_);
    return value_;
}

void read_thread(int threadnum)
{
    while(true)
    {
        if(g_rw == 0)
        {
            if(thread_read == threadnum)
            {
                unsigned int r = read(threadnum);
                std::lock_guard<std::mutex> g(mutex_screen);
                cout << "Thread : " << threadnum << ", " << value_ << endl;

                if( r > 99)
                {
                    break;
                }
                thread_read ++;
                if(thread_read >4 )
                {
                    thread_read = 1;
                    g_rw = 1;
                }
            }
        }
    }
}

void write()
{
    while(true)
    {
        if(g_rw == 1)
        {
            std::unique_lock<std::shared_mutex> lock(mutex_);
            value_++;

            std::lock_guard<std::mutex> g(mutex_screen);
            cout << "Write: " << value_ << endl;
            g_rw = 0;
        }

        if(value_ == 100)
            break;
    }
}

void shared_mutex_main()
{
    std::thread wt(write);
    std::thread rt1(read_thread, 1);
    std::thread rt2(read_thread, 2);
    std::thread rt3(read_thread, 3);
    std::thread rt4(read_thread, 4);
    wt.join();
    rt1.join();
    rt2.join();
    rt3.join();
    rt4.join();


}
