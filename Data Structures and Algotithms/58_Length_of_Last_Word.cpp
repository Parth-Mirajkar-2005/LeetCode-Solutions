//58. Length of Last Word
//
//Given a string s consisting of words and spaces, return the length of the last word in the string.
//A word is a maximal substring consisting of non-space characters only.
//
//Example 1:
//Input: s = "Hello World"
//Output: 5
//Explanation: The last word is "World" with length 5.
//
//Example 2:
//Input: s = "   fly me   to   the moon  "
//Output: 4
//Explanation: The last word is "moon" with length 4.
//
//Example 3:
//Input: s = "luffy is still joyboy"
//Output: 6
//Explanation: The last word is "joyboy" with length 6.

// ----------------------------------------- Solution 1 ---------------------------------------

// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int length = 0;
//         int auxilary_length = 0;
//         for(int i = 0; i < s.size(); i++)
//         {
//             if(s[i] == ' ')     
//             {
//                 if(auxilary_length != 0)
//                 {
//                     length = auxilary_length;
//                     auxilary_length = 0;
//                 }
//             }
//             else
//             {
//                 auxilary_length++;
//             }
//         }

//         if (auxilary_length != 0) {
//             length = auxilary_length;
//         }

//         return length;
//     }
// };

// --------------------------------------- Solution 2------------------------------------------------

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        while(i >= 0 && s[i] == ' ')
            i--;

        while(i >= 0 && s[i] != ' ')
        {
            length++;
            i--;
        }

        return length;
    }
};
