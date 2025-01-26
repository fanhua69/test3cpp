//
//  findKthSmalledIn2Sorted_2.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-17.
//
#include <vector>
#include <iostream>

using namespace std;

int solve2(  vector<int>& A, vector<int>& B, int k)
{
    // If the segment of on array is empty, it means we have passed all
    // its element, just return the corresponding element in the other
    // array.
    if (A.size() == 0)
    {
        return B[k];
    }

    if (B.size() == 0)
    {
        return A[k];
    }

    // Get the middle indexes and middle values of A and B.
    int aIndex = A.size() / 2;
    int bIndex = B.size() / 2;
    int aValue = A[aIndex];
    int bValue = B[bIndex];

    // If k is in the right half of A + B, remove the smaller left half.
    if (aIndex + bIndex < k)
    {
        if (aValue > bValue)
        {
            vector<int> b2 { B.begin() + bIndex - 1, B.end()};
            return solve2(A, b2, k - bIndex);
        }
        else
        {
            vector<int> a2{A.begin() + aIndex + 1, A.end()};
            return solve2(a2, B, k - aIndex);
        }
    }
    // Otherwise, remove the larger right half.
    else
    {
        if (aValue > bValue)
        {
            vector<int> a2 {A.begin(), A.begin() + aIndex };
            return solve2(a2, B, k);
        }
        else
        {
            vector<int> b2{B.begin(), B.begin() + bIndex};
            return solve2(A, b2, k);
        }
    }
    return -1;
}

void findKthSmallestIn2SortedArrays2_main()
{
    vector<int> a {0,1,2,3,4};
    vector<int> b {0,1,2,3,4};
    cout << solve2(a, b, 4) << endl;
}
