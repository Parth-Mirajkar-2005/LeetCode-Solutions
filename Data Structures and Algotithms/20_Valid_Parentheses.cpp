//20. Valid Parentheses
//
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
//determine if the input string is valid.
//
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
// 
//Example 1:
//Input: s = "()"
//Output: true
//
//Example 2:
//Input: s = "()[]{}"
//Output: true
//
//Example 3:
//Input: s = "(]"
//Output: false
//
//Example 4:
//Input: s = "([])"
//Output: true

class Solution {
public:
    bool isValid(string str) {
        stack<char> S;

        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == '(' || str[i] == '[' ||  str[i] == '{')
                S.push(str[i]);
            else
            {
                if (S.empty())
                    return false;

                if((str[i] == ')' && S.top() !='(') || 
                   (str[i] == ']' && S.top() !='[') || 
                   (str[i] == '}' && S.top() !='{'))
                    return false;
                else
                    S.pop();
            }
        }

        return S.empty();
    }
};
