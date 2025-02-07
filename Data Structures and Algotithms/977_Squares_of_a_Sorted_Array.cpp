//977. Squares of a Sorted Array
//
//Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
//
//Example 1:
//Input: nums = [-4,-1,0,3,10]
//Output: [0,1,9,16,100]
//
//Explanation: After squaring, the array becomes [16,1,0,9,100].
//After sorting, it becomes [0,1,9,16,100].
//
//Example 2:
//Input: nums = [-7,-3,2,3,11]
//Output: [4,9,9,49,121]

// ------------------------------------------------------- Solutions--------------------------------------------------------------

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             if(nums[i] < 0) 
//                 nums[i] *= (-1);
//         }

//         sort(nums.begin() , nums.end());

//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             nums[i] *= nums[i]; 
//         }

//         return nums;
//     }
// };

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             (nums[i] < 0) ? nums[i] *= (-1) : nums[i];
//             nums[i] *= nums[i]; 
//         }

//         sort(nums.begin() , nums.end());

//         return nums;
//     }
// };

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             if(nums[i] < 0) 
//                 nums[i] *= (-1);
//             nums[i] *= nums[i]; 
//         }

//         sort(nums.begin() , nums.end());
        
//         return nums;
//     }
// };

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for(int i = 0 ; i < nums.size() ; i++)
//             nums[i] *= nums[i];

//         sort(nums.begin() , nums.end());
        
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int start = 0 ; int end = nums.size()-1;
        int ptr = nums.size()-1;

        while((start <= end) && (ptr >= 0))
        {
            if((nums[start] * nums[start]) > (nums[end] * nums[end]))
                ans[ptr--] = nums[start] * nums[start++];
            else if((nums[start] * nums[start]) < (nums[end] * nums[end]))
                ans[ptr--] = nums[end] * nums[end--];
            else
                ans[ptr--] = nums[start] * nums[start++];
        }

        return ans;
    }
};
