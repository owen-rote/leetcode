/*
Leetcode #1455 Check If a Word OCcurs As a PRefix of Any Word in a Sentence
https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/
1 December 2024
Time Complexity: O(n) Two pointer approach!
Space Complexity: O(1)
*/

int isPrefixOfWord(char* sentence, char* searchWord) {
  int i = 0;
  int j = 0;
  int wordCount = 1;

  while (sentence[i] != '\0') {
    if (sentence[i] == searchWord[j]) {
      ++i;
      ++j;

      if (searchWord[j] == '\0') {
        return wordCount;
      }

    } else {
      while (sentence[i] != ' ' && sentence[i] != '\0') {
        // Skip current word
        ++i;
      }

      if (sentence[i] == ' ') {
        // Put i at start of next word
        ++i;
      }
      ++wordCount;
      j = 0;
    }
  }

  return -1;
}