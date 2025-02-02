// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
// You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

// Example 1:

// Input: nums = [1]
// Output: true
// Explanation:
// There is only one element. So the answer is true.

// Example 2:

// Input: nums = [2,1,4]
// Output: true
// Explanation:
// There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

// Example 3:
// Input: nums = [4,3,1,6]
// Output: false
// Explanation:
// nums[1] and nums[2] are both odd. So the answer is false.

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


class Solution {
public:
    static bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 1;
        bool prev=nums[0]&1;
        for (int i=1; i<n; i++){
            bool x=nums[i]&1;
            if (x^prev==0) return 0;
            prev=x;
        }
        return 1;
    }
};