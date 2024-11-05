/*
Leetcode #1957 Delete Characters to Make Fancy String
https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/
4 November 2024
Time Complexity: O(n)
Space Complexity: O(1) Inplace!!
*/

#include <string.h>

char* makeFancyString(char* s) {
  int size = strlen(s);

  int count = 1;
  int j = 1;
  for (int i = 1; i < size; ++i) {
    if (s[i] == s[i - 1]) {
      ++count;
    } else {
      count = 1;
    }
    if (count >= 3) {
      continue;
      --j;
    }
    s[j] = s[i];
    ++j;
  }

  s[j] = '\0';
  return s;
}