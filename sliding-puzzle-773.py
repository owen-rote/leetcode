"""
Leetcode #773 Sliding Puzzle
https://leetcode.com/problems/sliding-puzzle/description/
24 November 2024
Time Complexity: O(1)
Space Complexity: O(1)
There really is no n for this problem. The board size is always the same.

This approach turns the 3x2 matrix into a flat string for easy comparisons
"""

from collections import deque


class Solution:
    def slidingPuzzle(self, board: list[list[int]]) -> int:
        # These are the string indexes where 0 is able to go for each index.
        adjacencies = {
            0: [1, 3],
            1: [0, 2, 4],
            2: [1, 5],
            3: [0, 4],
            4: [1, 3, 5],
            5: [2, 4],
        }
        # Make board into a flat string: [[1,2,3], [4,5,0]] -> "123450"
        board = "".join([str(c) for row in board for c in row])

        # deque of tuple (i, board, length)
        queue = deque([(board.index("0"), board, 0)])

        visited = set([board])

        # BFS of all possible sliding options for 0
        while queue:
            i, board, length = queue.popleft()

            if board == "123450":
                # Solution found!
                return length

            board_array = list(board)
            for j in adjacencies[i]:
                new_board_array = board_array.copy()

                new_board_array[i] = board_array[j]
                new_board_array[j] = board_array[i]

                new_board = "".join(new_board_array)

                if new_board not in visited:
                    queue.append((j, new_board, length + 1))
                    visited.add(new_board)

        return -1
