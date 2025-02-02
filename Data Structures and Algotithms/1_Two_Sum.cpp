//1. Two Sum

//Hint
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.
//

//Example 1:
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

//Example 2:
//Input: nums = [3,2,4], target = 6
//Output: [1,2]

//Example 3:
//Input: nums = [3,3], target = 6
//Output: [0,1]


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans(2);  // Initialize vector with size 2

//         for (size_t i = 0; i < nums.size() - 1; i++) {
//             for (size_t j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] + nums[j] == target) {
//                     ans[0] = i;
//                     ans[1] = j;
//                     return ans;  // Return immediately when solution is found
//                 }
//             }
//         }

//         return {}; // Return an empty vector if no solution is found
//     }
// };

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int complement = target - nums[i];

            if (mp.count(complement)) { // Faster lookup than `find()`
                return {mp[complement], i};
            }

            mp[nums[i]] = i; // Store the number and its index
        }

        return {}; // This should never be reached as per problem constraints
    }
};

