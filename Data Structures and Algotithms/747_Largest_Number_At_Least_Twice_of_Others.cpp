//747. Largest Number At Least Twice of Others
//
//You are given an integer array nums where the largest integer is unique.
//Determine whether the largest element in the array is at least twice as much as every other number in the array. 
//If it is, return the index of the largest element, or return -1 otherwise.
//
//Example 1:
//Input: nums = [3,6,1,0]
//Output: 1
//Explanation: 6 is the largest integer.
//For every other number in the array x, 6 is at least twice as big as x.
//The index of value 6 is 1, so we return 1.
//
//Example 2:
//Input: nums = [1,2,3,4]
//Output: -1
//Explanation: 4 is less than twice the value of 3, so we return -1.

// ----------------------------------------------------------------- Solution ------------------------------------------------------------

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // if(nums.size() == 0)
        //     return -1;
        // if(nums.size() == 1)
        //     return 0;

        if(nums.size() <= 1)
            return (nums.size() - 1);

        int L1 = 0,L2 = -1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[L1])
            {
                L2 = L1;
                L1 = i;
            }
            else if(L2 == -1 || nums[i] > nums[L2])
            {
                L2 = i;
            }
        }

        return (L2 == -1 || nums[L1] >= 2*nums[L2]) ? (L1) : (-1);
    }
};
