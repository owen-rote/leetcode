/*
Leetcode #14 Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/
15 November 2024
Time Complexity: O(n*m) (number of total characters)
Space Complexity: O(n) (zero additional space is used other than result)
*/

char* longestCommonPrefix(char** strs, int strsSize) {
    int len = strlen(strs[0]);
    // Allocate new string
    char* result = (char*)malloc(len + 1);
    result[0] = '\0';

    // For each character of current string
    for (int i = 0; i < len; ++i) {
        // For each string in strs
        for (int j = 0; j < strsSize; ++j) {
            // i: current char; j: current string
            if (result[i] == '\0') {
                result[i] = strs[j][i];
                result[i + 1] = '\0';
            } else if (strs[j][i] != result[i]) {
                result[i] = '\0';
                return result;
            }
        }
    }
    return result;
}