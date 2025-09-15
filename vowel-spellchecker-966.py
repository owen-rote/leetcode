"""
Leetcode #966 Vowel Spellchecker
https://leetcode.com/problems/vowel-spellchecker/
14 September 2025
Time Complexity: O(c) where c is num of chars in wordlist + queries
Space Complexity: O(c)
"""


class Solution:
    def spellchecker(self, wordlist: list[str], queries: list[str]) -> list[str]:
        result = list()
        wordlist_set = set(wordlist)
        lower_word_dict = dict()
        devoweled_word_dict = dict()

        # Construct de-voweled and lower-case wordlist
        for word in wordlist:
            word_low = word.lower()
            if word_low not in lower_word_dict:
                lower_word_dict[word_low] = word
            devoweled_word_dict.setdefault(self.insert_stars(word_low), word)
            devoweled_word = self.insert_stars(word_low)
            if devoweled_word not in devoweled_word_dict:
                devoweled_word_dict[devoweled_word] = word

        # Iterate thru queries
        for query in queries:
            # Check for exact match
            if query in wordlist_set:
                result.append(query)
                continue

            # Check for capitalization match
            query_low = query.lower()
            if query_low in lower_word_dict:
                result.append(lower_word_dict[query_low])
                continue

            # Check for vowel error match
            devoweled_word = self.insert_stars(query_low)
            if devoweled_word in devoweled_word_dict:
                result.append(devoweled_word_dict[devoweled_word])
                continue

            result.append("")

        return result

    def insert_stars(self, word):
        return "".join("*" if c in "aeiou" else c for c in word)
