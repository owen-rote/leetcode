/*
Leetcode #796 Rotate String
https://leetcode.com/problems/rotate-string/description/
3 November 2024
Time Complexity: O(n + m)
Space Complexity: O(m)

This approach precomputes a prefix sum array, then, for each query, just check
the prefix array.
*/

#include <stdbool.h>

bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize,
                     int* queriesColSize, int* returnSize) {
  bool* result = malloc(sizeof(bool) * queriesSize);
  *returnSize = queriesSize;
  int* prefix = malloc(sizeof(int) * numsSize);

  prefix[0] = 1;
  int prev = nums[0] % 2;
  for (int i = 1; i < numsSize; ++i) {
    if (prev != nums[i] % 2) {
      prefix[i] = prefix[i - 1] + 1;
    } else {
      prefix[i] = 1;
    }
    prev = nums[i] % 2;
  }

  for (int i = 0; i < queriesSize; ++i) {
    result[i] =
        prefix[queries[i][1]] > queries[i][1] - queries[i][0] ? true : false;
  }

  free(prefix);
  return result;
}

// Don't forget to free(result) after calling