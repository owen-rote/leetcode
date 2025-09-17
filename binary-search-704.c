/*
Leetcode #704 Binary Search
https://leetcode.com/problems/binary-search/
12 November 2024
Time Complexity: O(log(n))
Space Complexity: O(1)
*/

int search(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (target < nums[mid]) {
            r = mid - 1;
        } else if (target > nums[mid]) {
            l = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}