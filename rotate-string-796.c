/*
Leetcode #796 Rotate String
https://leetcode.com/problems/rotate-string/description/
3 November 2024
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool rotateString(char* s, char* goal) {
  int length = strlen(s);

  if (length != strlen(goal)) {
    return false;
  }

  char concatinated[length * 2 + 1];
  
  // Declare as empty string to ignore garbage values when declaring
  concatinated[0] ='\0';

  strcat(concatinated, s);
  strcat(concatinated, s);

  return strstr(concatinated, goal) != NULL;
}