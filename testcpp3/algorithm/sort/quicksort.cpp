//
//  quicksort.cpp
//  testcpp2
//
//  Created by hua fan on 2023-08-23.
//

#include <stdio.h>
#include "headers.h"


int partition(vector<int> &data, int f, int t)
{
    int pivot = data[f];
    int i = f;
    int j = t;

    while(i<j)
    {
        while(i <= t && data[i] <= pivot)
        {
            i++;
        }

        while(j >= 0 && data[j] > pivot)
        {
            j--;
        }

        if(i<j)
        {
            swap(data[i], data[j]);
        }
    }

    if( j > f)
        swap(data[f],data[j]);

    return j;
}


void quicksort(vector<int> &data, int f, int t)
{
    if(f < t)
    {
        int j = partition(data,f,t);
        quicksort(data, f, j);
        quicksort(data, j+1, t);
    }
}


void quicksortMain()
{

    vector<int> data ={5,4,3,2,1};
    quicksort(data, 0 , data.size()-1);

    printme(data,",.");
}
