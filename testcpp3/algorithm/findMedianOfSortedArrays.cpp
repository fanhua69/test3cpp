//
//  findMedianOfSortedArrays.cpp
//  testcpp3
//
//  Created by hua fan on 2024-06-02.
//

#include <stdio.h>
#include "headers.h"

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{

    int total = nums1.size() + nums2.size();
    int cutpos1 = nums1.size() / 2;
    int cutpos2 = total / 2 - cutpos1;

    while(cutpos1 < nums1.size() - 1  && cutpos2 < nums2.size() - 1)
    {
        if (nums1[cutpos1] <= nums2[cutpos2+1] && nums2[cutpos2] <= nums1[cutpos1+1])
        {
            break;
        }

        if (nums1[cutpos1] > nums2[cutpos2])
        {
            cutpos1=cutpos1/2;
        }
        else if (nums1[cutpos1 + 1] < nums2[cutpos2])
        {
            cutpos1= (cutpos1 + nums1.size()) / 2;
        }
        cutpos2 = total / 2 - cutpos1;
    }

    int l1 = max(nums1[cutpos1], nums2[cutpos2]);
    int l2 = min (nums1[cutpos1+1], nums2[cutpos2+1]);

    return (l1 + l2)/2.0;

}


void findMedianOfSortedArraysMain()
{
    vector<int> v1 {1,3}, v2{2};
    double d = findMedianSortedArrays(v1, v2);
    cout << d << endl;
}
