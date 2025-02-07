//167. Two Sum II - Input Array Is Sorted
//
//Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
//Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
//Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
//The tests are generated such that there is exactly one solution. You may not use the same element twice.
//Your solution must use only constant extra space.
//
//Example 1:
//Input: numbers = [2,7,11,15], target = 9
//Output: [1,2]
//
//Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
//Example 2:
//Input: numbers = [2,3,4], target = 6
//Output: [1,3]
//
//Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
//
//Example 3:
//Input: numbers = [-1,0], target = -1
//Output: [1,2]
//Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

// ------------------------------------------------------- Solutions ------------------------------------------------------------------

// int search(vector<int>& numbers, int start,  int target) {
//     for (int i = start; i < numbers.size(); i++) {
//         if (numbers[i] == target) return i;
//     }
//     return -1; 
// }

// int search(vector<int>& numbers, int start,  int key) {
//     int low = start;
//     int high = numbers.size() - 1;
//     int mid;

//     while(low <= high)
//     {
//         mid = (low + high) / 2;

//         if(key == numbers[mid])
//             return mid;
        
//         (key < numbers[mid]) ? (high = mid - 1) : (low = mid + 1);
//     }

//     return -1;
// }

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int> ans(2);
//         if(numbers.size() == 2)
//         {
//             ans[0] = 1;
//             ans[1] = 2;

//             return ans;
//         }

//         for(int i = 0 ; i < numbers.size() ; i++)
//         {
//             int pos = search(numbers, (i+1), (target - numbers[i]));   
            
//             if(pos != -1)
//             {
//                 ans[0] = i+1;
//                 ans[1] = pos+1;

//                 break;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        if(numbers.size() == 2)
        {
            ans[0] = 1;
            ans[1] = 2;

            return ans;
        }

        int start = 0, end = numbers.size() - 1;

        while(start < end)
        {
            if(target == numbers[start] + numbers[end])
            {
                ans[0] = start+1;
                ans[1] = end+1;

                return ans;
            }

            (target > (numbers[start] + numbers[end])) ? (start++) : (end--);
        }

        return ans;
    }
};
