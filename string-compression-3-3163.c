/*
Leetcode #3163 String Compression III
https://leetcode.com/problems/string-compression-iii/description/
4 November 2024
Time Complexity: O(n)
Space Complexity: O(n)
RUNS 3x FASTER THAN PYTHON VERSION!!
*/

#include <stdio.h>

char* compressedString(char* word) {
  int len = strlen(word);
  // Allocate comp string on heap so it isn't freed when returning
  char* comp = malloc((2 * len + 1) * sizeof(char));
  // Set string to be empty
  comp[0] = '\0';
  int count = 1;

  // Keep track of end of comp string. This avoids O(n) strcat
  int compIndex = 0;

  for (int i = 0; i < len; ++i) {
    // If not end & current == next & count != 9
    if (i != len - 1 && word[i] == word[i + 1] && count != 9) {
      ++count;
      continue;
    }

    // Make buffer array on for loop stack to hold ['%d', '%c', '\0']
    // Loop stack is deleted after each loop, so this is new each time.
    char buffer[3];

    // sprintf: same as printf but outputs to the string instead of console
    // It returns number of chars written
    compIndex += sprintf(&comp[compIndex], "%d%c", count, word[i]);
    count = 1;
  }
  comp[compIndex] = '\0';
  return comp;
}