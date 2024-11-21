/*
Leetcode #74 Search a 2D Matrix
https://leetcode.com/problems/search-a-2d-matrix/
18 November 2024
Time Complexity: O(log(n*m)) Double binary search!
Space Complexity: O(1)
*/

#include <stdbool.h>

bool searchMatrix(int** matrix, int rows, int* columns, int target) {
  int l = 0;
  int r = rows - 1;
  int targetRow;

  // Top to bottom binary search =========================
  // l == bottom; r == top;
  // Finds targetRow where target is within its range
  while (l <= r) {
    targetRow = (l + r) / 2;
    if (target < matrix[targetRow][0]) {
      r = targetRow - 1;
    } else if (target > matrix[targetRow][*columns - 1]) {
      l = targetRow + 1;
    } else {
      break;
    }
  }

  // Left to right binary search =========================
  l = 0;
  r = *columns - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (target < matrix[targetRow][mid]) {
      r = mid - 1;
    } else if (target > matrix[targetRow][mid]) {
      l = mid + 1;
    } else {
      return true;
    }
  }

  return false;
}