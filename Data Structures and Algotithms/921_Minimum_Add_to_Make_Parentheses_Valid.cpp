//921. Minimum Add to Make Parentheses Valid
//
//A parentheses string is valid if and only if:
//It is the empty string,
//It can be written as AB (A concatenated with B), where A and B are valid strings, or
//It can be written as (A), where A is a valid string.
//You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
//
//For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
//Return the minimum number of moves required to make s valid.
//
//Example 1:
//Input: s = "())"
//Output: 1
//
//Example 2:
//Input: s = "((("
//Output: 3

class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<char> S;
        int count = 0;

        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '(')
                S.push(str[i]);
            else
            {
                if (S.empty())
                    count++;
                else if(str[i] == ')' && S.top() !='(')
                    count++;
                else
                    S.pop();
            }
        }

        // while(!S.empty())
        // {
        //     count++;
        //     S.pop();
        // }

        count += S.size();

        return count; 
    }
};
