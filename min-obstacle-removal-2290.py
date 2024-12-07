"""
Leetcode #2290 Minimum Obstacle Removal to Reach Corner
https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/
28 November 2024
Time Complexity: O(n*m*log(n*m))
Space Complexity: O(1)
This solution uses Dijkstra's algorithm
"""

import heapq


class Solution:
    def minimumObstacles(self, grid: list[list[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])

        min_heap = [(0, 0, 0)]  # (obstacles, row, col)
        visited = set([(0, 0)])  # Visited hash table

        while min_heap:
            obstacles, r, c = heapq.heappop(min_heap)

            if (r, c) == (ROWS - 1, COLS - 1):
                return obstacles

            nei = [[r + 1, c], [r - 1, c], [r, c + 1], [r, c - 1]]
            for nr, nc in nei:
                if (nr, nc) in visited or nr < 0 or nc < 0 or nc == COLS or nr == ROWS:
                    continue
                heapq.heappush(min_heap, (obstacles + grid[nr][nc], nr, nc))
                visited.add((nr, nc))
