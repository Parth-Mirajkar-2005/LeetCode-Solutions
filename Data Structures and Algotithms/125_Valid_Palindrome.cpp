//125. Valid Palindrome
//
//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
//removing all non-alphanumeric characters, it reads the same forward and backward. 
//Alphanumeric characters include letters and numbers.
//
//Given a string s, return true if it is a palindrome, or false otherwise.
//
//Example 1:
//Input: s = "A man, a plan, a canal: Panama"
//Output: true
//Explanation: "amanaplanacanalpanama" is a palindrome.
//
//Example 2:
//Input: s = "race a car"
//Output: false
//Explanation: "raceacar" is not a palindrome.
//
//Example 3:
//Input: s = " "
//Output: true
//Explanation: s is an empty string "" after removing non-alphanumeric characters.
//Since an empty string reads the same forward and backward, it is a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        string buffer = "";
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(isalnum(s[i]))
                buffer.push_back(s[i]);
        }

        int low, high;
        low = 0;
        high = buffer.size() - 1;
        while(low <= high)
        {
            if(buffer[low] == buffer[high])
            {
                low++;
                high--;
            }
            else
                return false;
        }

        return true;
    }
};
