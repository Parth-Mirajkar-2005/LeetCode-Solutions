//1394. Find Lucky Integer in an Array

//Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
//Return the largest lucky integer in the array. If there is no lucky integer return -1.

//Example 1:
//Input: arr = [2,2,3,4]
//Output: 2
//Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

//Example 2:
//Input: arr = [1,2,2,3,3,3]
//Output: 3
//Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

//Example 3:
//Input: arr = [2,2,2,3,3]
//Output: -1
//Explanation: There are no lucky numbers in the array.

// ---------------------------------------- Solution 1: ---------------------------------------------------

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> hm;                                                  

        for(int i = 0; i < arr.size(); i++) {
            int ele = arr[i];

            if(hm.find(ele) != hm.end()) {
                hm[ele] = hm[ele] + 1;
            } else {
                hm[ele] = 1;
            }
        }

        int ans = -1;

        for(auto& pair : hm) {
            if(pair.second == pair.first) {
                ans = max(ans, pair.first);
            }
        }

        return ans;
    }
};

// ---------------------------------------- Solution 2: ---------------------------------------------------

// class Solution {
// public:
//     int findLucky(vector<int>& arr) {
//         unordered_map<int, int> freq;

//         int max = INT_MIN;

//         for (int i = 0 ; i <arr.size() ; i++)
//         {
//             freq[arr[i]]++;
//         }

//         for (auto num : freq)
//         {

//             if(num.first == num.second)
//             {
//                 if(num.second > max)
//                 {
//                     max = num.second;
//                 }
//             }
//         }

//         if(max>0)
//         {
//             return max;
//         }
//         return -1;
//     }
// };
