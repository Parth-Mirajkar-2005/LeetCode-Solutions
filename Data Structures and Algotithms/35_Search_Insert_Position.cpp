//35. Search Insert Position

//Given a sorted array of distinct integers and a target value, return the index if the target is found. 
//If not, return the index where it would be if it were inserted in order.
//You must write an algorithm with O(log n) runtime complexity.

//Example 1:
//Input: nums = [1,3,5,6], target = 5
//Output: 2

//Example 2:
//Input: nums = [1,3,5,6], target = 2
//Output: 1

//Example 3:
//Input: nums = [1,3,5,6], target = 7
//Output: 4

// ----------------------------------- Solution 1 ---------------------------------------

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int low = 0, high = nums.size() - 1;

//         while(low <= high)
//         {
//             int mid = low + (high - low) / 2;

//             if(nums[mid] == target)
//                 return mid;
//             else if(nums[mid] < target)
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//         }

//         // low is the insertion point if not found
//         return low;
//     }
// };

// ---------------------------------- Solution 2 --------------------------------------

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // If array is empty
        if(nums.size() == 0)
            return 0;

        // For the edge cases
        if(nums[0] >= target)
            return 0;
        else if(nums[nums.size() - 1] < target)
            return nums.size();

        int low, high, mid;
        low = 0; // changed from 1 to 0
        high = nums.size() - 1; // changed from nums.size() - 2 to nums.size() - 1

        while(low <= high)
        {
            mid = low + (high - low) / 2;
            // If element is already present
            if(nums[mid] == target)
                return mid;

            // If element is not there in the array
            if(nums[mid] < target && nums[mid + 1] > target)
                return mid + 1;

            if(nums[mid] > target && mid > 0 && nums[mid - 1] < target)
                return mid;

            // Resize the search space
            if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1; // This will never be reached actually
    }
};
