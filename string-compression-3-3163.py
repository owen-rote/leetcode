"""
Leetcode #3163 String Compression III
https://leetcode.com/problems/string-compression-iii/description/
4 November 2024
Time Complexity: O(n)
Space Complexity: O(n)
Wanna run this 3 times faster? Check the C implementation
"""


class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""
        length = len(word)
        count = 1

        for i in range(length):
            if i != length - 1:
                if word[i] == word[i + 1] and count != 9:
                    count += 1
                    continue
            comp += str(count)
            comp += word[i]
            count = 1

        return comp
