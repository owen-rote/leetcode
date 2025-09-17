/*
Leetcode #2914 Minimum Number of Changes to Make Binary String Beautiful
https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/
4 November 2024
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <string.h>

int minChanges(char* s) {
    int min_changes = 0;
    int length = strlen(s);

    // Assumes partitions of exactly two.
    // If nums in partition aren't equal, min_changes++;
    for (int i = 0; i < length; i += 2) {
        if (s[i] != s[i + 1]) {
            ++min_changes;
        }
    }
    return min_changes;
}