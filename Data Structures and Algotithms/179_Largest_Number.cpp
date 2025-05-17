//179. Largest Number
//
//Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//Since the result may be very large, so you need to return a string instead of an integer.
//
//Example 1:
//Input: nums = [10,2]
//Output: "210"
//
//Example 2:
//Input: nums = [3,30,34,5,9]
//Output: "9534330"

// ------------------------------------- Solution --------------------------------

// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         string ans = "";

//         for(int i = 0 ; i < nums.size() ; i++)
//         {
//             string front_append;
//             string back_append;

//             front_append = ans + to_string(nums[i]);
//             back_append = to_string(nums[i]) + ans;

//             if(front_append > back_append)
//                 ans = front_append;
//             else
//                 ans = back_append;            
//         }
//         return ans;
//     }
// };

// ------------------------------------- The above code falis some of the test case -------------------------------------

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";

        // Step 1: Convert numbers to strings
        vector<string> strNums;
        for (int num : nums) 
        {
            strNums.push_back(to_string(num));
        }

        // Step 2: Sort using custom comparator
        sort(strNums.begin(), strNums.end(), [](string &a, string &b) 
        {
            return a + b > b + a;  // Compare combined strings
        });

        // Step 3: Handle edge case where all numbers are "0"
        if (strNums[0] == "0") return "0";

        // Step 4: Build the largest number
        for (string s : strNums) 
        {
            ans += s;
        }

        return ans;
    }
};
