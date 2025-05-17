//75. Sort Colors
//
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color 
//are adjacent, with the colors in the order red, white, and blue.
//
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//You must solve this problem without using the library's sort function. 
//
//Example 1:
//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
//
//Example 2:
//Input: nums = [2,0,1]
//Output: [0,1,2]

// ------------------------ Solution 1 ----------------------------

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int ones = 0;
//         int twos = 0;
//         int i, j;
//         for(i = 0, j = 0; i < nums.size(); i++)
//         {
//             if(nums[i] == 0)
//                 nums[j++] = 0;
//             else if(nums[i] == 1)
//                 ones++;
//             else 
//                 twos++;
//         }
//         while(ones > 0)
//         {
//             nums[j++] = 1;
//             ones--;
//         }
//         while(twos > 0)
//         {
//             nums[j++] = 2;
//             twos--;
//         }
//     }
// };

//  ------------------------- Solution 2 -----------------------------------
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low, mid, high;
        low = mid = 0;
        high = nums.size() - 1;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
