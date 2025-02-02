// 1752. Check if Array Is Sorted and Rotated

// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
// There may be duplicates in the original array.
// Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

// Example 2:
// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.

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

// int min_idx(vector<int>& nums)
// {
//     int idx = 0;
//     for(int i = 0 ; i < nums.size() ; i++)
//     {
//         if(nums[i] < nums[idx])
//             idx = i;
//     }

//     return idx;
// }

// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int min_ele_idx = min_idx(nums);

//         bool flag = true;
//         int i = min_ele_idx;
//         do
//         {
//             if(nums[i % nums.size()] > nums[(i+1) % nums.size()])
//             {
//                 flag = false;
//                 break;
//             }
//             i = (i+1) % nums.size();
//         }while(i != (min_ele_idx % nums.size()) - 1);

//         return flag;
//     }
// };

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i+1) % n]) // Check if out of order
                count++;
            if(count > 1) return false; // More than one break in order
        }
        return true;
    }
};
