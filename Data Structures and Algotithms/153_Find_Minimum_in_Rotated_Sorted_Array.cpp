//153. Find Minimum in Rotated Sorted Array

//Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
//[4,5,6,7,0,1,2] if it was rotated 4 times.
//[0,1,2,4,5,6,7] if it was rotated 7 times.
//Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
//Given the sorted rotated array nums of unique elements, return the minimum element of this array.

//You must write an algorithm that runs in O(log n) time.

//Example 1:
//Input: nums = [3,4,5,1,2]
//Output: 1
//Explanation: The original array was [1,2,3,4,5] rotated 3 times.

//Example 2:
//Input: nums = [4,5,6,7,0,1,2]
//Output: 0
//Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

//Example 3:
//Input: nums = [11,13,15,17]
//Output: 11
//Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int low, high, mid;
//         low = 0;
//         high = nums.size() - 1;
//         int min_ele = INT_MAX;

//         while(low <= high)
//         {
//             mid = (low + (high - low)) / 2;

//             // If the subarray is already sorted
//             if (nums[low] <= nums[high]) {
//                 min_ele = min(min_ele, nums[low]);
//                 break;
//             }
//             //Check for the first half is sorted orr not;
//             if(nums[low] < nums[mid])
//             {
//                 min_ele = min(nums[low], min_ele);
//                 low = mid+1;
//             }
//             //Else second half is sorted;
//             else
//             {
//                 min_ele = min(nums[mid], min_ele);
//                 high = mid-1;
//             }
//         } 

//         return min_ele;       
//     }
// };

// -------------------------- The above code fails the test case of [2, 1] ------------------------------

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        else if(nums[0] <= nums[nums.size() - 1])
            return nums[0];

        int low = 0, high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(mid > 0 && nums[mid] < nums[mid - 1]) // Found the minimum point
                return nums[mid];
            if(mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) // Pivot point
                return nums[mid + 1];

            // Adjust the search range
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return -1;
    }
};

