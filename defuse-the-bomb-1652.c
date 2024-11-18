/*
Leetcode #1652 Defuse the Bomb
https://leetcode.com/problems/defuse-the-bomb/description/
17 November 2024
Time Complexity: O(n) sliding window approach!!
Space Complexity: O(n) Prompt asks for new malloced array
*/

int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    // calloc makes array with default value of 0;
    int* result = calloc(codeSize, sizeof(int));
    *returnSize = codeSize;
    if (k == 0) {
        return result;
    }
    // Initialize sliding window values
    int start = 1;
    int end = k;
    int sum = 0;
    if (k < 0) {
        // Make starting point end of array
        start = codeSize - abs(k);
        end = codeSize - 1;
    }
    for (int i = start; i <= end; ++i) {
        // Get initial window sum
        sum += code[i];
    }
    for (int i = 0; i < codeSize; ++i) {
        result[i] = sum;
        sum -= code[start % codeSize];
        sum += code[(end + 1) % codeSize];
        ++start;
        ++end;
    }

    return result;
}