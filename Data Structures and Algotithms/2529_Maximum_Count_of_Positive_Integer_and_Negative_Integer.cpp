//2529. Maximum Count of Positive Integer and Negative Integer
//
//Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and 
//the number of negative integers.
//
//In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, 
//then return the maximum of pos and neg.
//
//Note that 0 is neither positive nor negative.
//
//Example 1:
//Input: nums = [-2,-1,-1,1,2,3]
//Output: 3
//Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
//
//Example 2:
//Input: nums = [-3,-2,-1,0,0,1,2]
//Output: 3
//Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
//
//Example 3:
//Input: nums = [5,20,66,1314]
//Output: 4
//Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if((nums[0] > 0) || (nums[nums.size() - 1] < 0))
            return nums.size();     
        
        int low_negetive, high_negetive, low_positive, high_positive;
        low_negetive = low_positive = 0;
        high_negetive = high_positive = nums.size() - 1;
        int pos_last_negetive = -1;
        int pos_first_positive = nums.size();

        while(low_negetive <= high_negetive)
        {
            int mid = (low_negetive + high_negetive) / 2;
            if(nums[mid] >= 0)
                high_negetive = mid - 1;
            else if(nums[mid] < 0)
            {
                pos_last_negetive = mid;
                low_negetive = mid + 1;
            }
        }

        while(low_positive <= high_positive)
        {
            int mid = (low_positive + high_positive) / 2;
            if(nums[mid] <= 0)
                low_positive = mid + 1;
            else if(nums[mid] > 0)
            {
                pos_first_positive = mid;
                high_positive = mid - 1;
            }
        }

        int negative_count = pos_last_negetive + 1;  
        int positive_count = nums.size() - pos_first_positive;
        
        return max(negative_count, positive_count);
    }
};
