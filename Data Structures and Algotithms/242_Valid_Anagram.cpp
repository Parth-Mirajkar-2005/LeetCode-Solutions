//242. Valid Anagram
//
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.

//Anagram : 
//Is is a word or phrase form by rearrenging the letter of the different word or phrase using 
//all the available letter only once.
//
//Example 1:
//Input: s = "anagram", t = "nagaram"
//Output: true
//
//Example 2:
//Input: s = "rat", t = "car"
//Output: false

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;

        vector<int> occurance(26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            occurance[s[i] - 'a'] += 1;
            occurance[t[i] - 'a'] -= 1;
        }

        for(int i = 0; i < 26; i++)
            if(occurance[i] != 0)
                return false;
                
        return true;
    }
};
