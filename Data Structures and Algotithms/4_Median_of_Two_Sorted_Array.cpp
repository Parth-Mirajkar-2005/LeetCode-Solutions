#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <cctype>
#include <vector>
using namespace std;

int main()
{
    
    
    return 0;
}

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5

// -->>

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> sorted(nums1.size() + nums2.size());
//         int i = 0, j = 0, k = 0;

//         while(i < nums1.size() && j < nums2.size())
//             (nums1[i] < nums2[j]) ? (sorted[k++] = nums1[i++]) : (sorted[k++] = nums2[j++]);
//         while(i < nums1.size()) sorted[k++] = nums1[i++];
//         while(j < nums2.size()) sorted[k++] = nums2[j++];

//         double ans = 0.0;
//         (k % 2 != 0) ? ans = (sorted[k/2]) : ans = ((sorted[k/2] + sorted[k/2 - 1]) / 2.0);

//         return ans;
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), sorted.begin());

        double ans = 0.0;
        int k = sorted.size();
        (k % 2 != 0) ? ans = (sorted[k/2]) : ans = ((sorted[k/2] + sorted[k/2 - 1]) / 2.0);

        return ans;
    }
};