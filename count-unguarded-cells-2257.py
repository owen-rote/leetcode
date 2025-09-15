"""
Leetcode #2257 Count Unguarded Cells in Grid
https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/
21 November 2024
Time Complexity: TODO
Space Complexity: TODO
This code doesn't work. TODO!!
"""


class Solution:
    def countUnguarded(self, m: int, n: int, guards: list[list[int]], walls: list[list[int]]) -> int:
        count = m * n
        matrix = [[0 for col in range(n)] for row in range(m)]

        for row, col in walls:
            # Set every wall to a 2 to signify WALL
            matrix[row][col] = 2
            count -= 1

        for row, col in guards:
            # Set every guard to a 3 to signify GUARD
            matrix[row][col] = 1
            count -= 1

        for row, col in guards:

            # Right
            for i in range(col + 1, n):
                if matrix[row][i] in (2, 3):
                    break

                if matrix[row][i] != 1:
                    count -= 1
                    matrix[row][i] = 1

            # Left
            for i in range(col - 1, -1, -1):
                if matrix[row][i] in (2, 3):
                    break

                if matrix[row][i] != 1:
                    count -= 1
                    matrix[row][i] = 1

            # Down
            for i in range(row + 1, m):
                if matrix[i][col] in (2, 3):
                    break

                if matrix[i][col] != 1:
                    count -= 1
                    matrix[i][col] = 1

            # Up
            for i in range(row - 1, -1, -1):
                if matrix[i][col] in (2, 3):
                    break

                if matrix[i][col] != 1:
                    count -= 1
                    matrix[i][col] = 1

        return count
