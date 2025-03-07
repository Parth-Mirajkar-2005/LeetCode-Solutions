//34. Find First and Last Position of Element in Sorted Array

//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].

//You must write an algorithm with O(log n) runtime complexity.

//Example 1:
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]

//Example 2:
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]

//Example 3:
//Input: nums = [], target = 0
//Output: [-1,-1]

int search(vector<int>& nums, int target) {
    int low, high, mid;
    low = 0;
    high = nums.size() - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(target == nums[mid])
            return mid;
        
        (target < nums[mid]) ? (high = mid-1) : (low = mid+1); 
    }

    return -1;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        
        int loc = search(nums, target);

        if(loc == -1)
            return ans;

        int i,j;
        i = j = loc;
        
        // while((i >= 0 && nums[i] == target) || (j <= nums.size()-1 && nums[j] == target))
        // {
        //         ans[0] = i--;
        //         ans[1] = j++;
        // }

        while(i >= 0 && nums[i] == target)
        {
                ans[0] = i;
                i--;
        }

        while(j <= nums.size()-1 && nums[j] == target)
        {
                ans[1] = j;
                j++;
        }

        return ans;
    }
};
