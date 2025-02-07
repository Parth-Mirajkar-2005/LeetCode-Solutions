//1790. Check if One String Swap Can Make Strings Equal
//
//You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
//Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
//
//Example 1:
//Input: s1 = "bank", s2 = "kanb"
//Output: true
//
//Explanation: For example, swap the first character with the last character of s2 to make "bank".
//
//Example 2:
//Input: s1 = "attack", s2 = "defend"
//Output: false
//
//Explanation: It is impossible to make them equal with one string swap.
//
//Example 3:
//Input: s1 = "kelb", s2 = "kelb"
//Output: true
//
//Explanation: The two strings are already equal, so no string swap operation is required.

// ------------------------------------------------------ Solutions ------------------------------------------------------------

// string rotate(string s, int steps) {
//     int n = s.length();
//     steps = steps % n;  // Handle cases where steps is greater than string length
//     return s.substr(n - steps) + s.substr(0, n - steps);
// }

// class Solution {
// public:
//     bool areAlmostEqual(string s1, string s2) {
//         if (s1.length() != s2.length()) {
//             return false;
//         } else if (s1 == s2) {
//             return true;  // If both are already equal, no rotation needed
//         }

//         // Rotate the string one step at a time
//         for (int i = 0; i < s1.length(); i++) {
//             s1 = rotate(s1, 1);  // Rotate s1 by 1 character
//             if (s1 == s2) {  // Check if rotated s1 matches s2
//                 return true;
//             }
//         }

//         return false;  // If no match found after full rotation
//     }
// };

// ################## The Above code is wrong for some reason #####################

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length()) return false;

        vector<int> diffIndices;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }

        // Strings are already equal
        if (diffIndices.empty()) return true;

        // There should be exactly two differences and swapping them should make strings equal
        if (diffIndices.size() == 2) {
            swap(s1[diffIndices[0]], s1[diffIndices[1]]);
            return s1 == s2;
        }

        return false;
    }
};

