/*
Leetcode #20 valid parenthesis
https://leetcode.com/problems/valid-parentheses/
12 November 2024
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stack>
#include <string>

bool isValid(std::string s) {
    std::stack<char> stack;
    stack.push(s[0]);
    for (int i = 1; i < s.length(); ++i) {
        // Check ()
        if (s[i] == ')') {
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            } else {
                return false;
            }
            // Check []
        } else if (s[i] == ']') {
            if (!stack.empty() && stack.top() == '[') {
                stack.pop();
            } else {
                return false;
            }
            // Check {}
        } else if (s[i] == '}') {
            if (!stack.empty() && stack.top() == '{') {
                stack.pop();
            } else {
                return false;
            }
        } else {
            stack.push(s[i]);
        }
    }
    return stack.empty();
}