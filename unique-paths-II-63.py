"""
Leetcode #63 Unique Paths II
https://leetcode.com/problems/unique-paths-ii/submissions/1472385386/
6 December 2024
Time Complexity: O(n*m)
Space Complexity: O(n*m)
This solution uses Dynamic Programming.
Runtime beats 100%, however memory beats 10%
"""


def uniquePathsWithObstacles(self, matrix: list[list[int]]) -> int:
    # Check if impossible
    if matrix[0][0] == 1:
        return 0

    r = len(matrix)
    c = len(matrix[0])

    # New matrix of zeroes for dynamic programming
    new = [[0 for col in range(c)] for row in range(r)]
    # Base case
    new[0][0] = 1

    for i in range(r):
        for j in range(c):
            if matrix[i][j] == 1:
                new[i][j] = 0
                continue

            above = left = 0

            # If next spot is valid, add the new number of paths to adjacent cells.
            if i > 0 and matrix[i - 1][j] != 1:
                above = new[i - 1][j]
            if j > 0 and matrix[i][j - 1] != 1:
                left = new[i][j - 1]

            new[i][j] += above + left

    return new[r - 1][c - 1]
