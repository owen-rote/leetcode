/*
Leetcode #19 Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
9 November 2024
Time Complexity: O(n)
Space Complexity: O(1)
Iterates through the list only once!
*/

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
  struct ListNode dummy;
  dummy.next = head;
  struct ListNode* left = &dummy;
  struct ListNode* right = head;

  // Move right forward n times
  while (n > 0 && right) {
    right = right->next;
    --n;
  }

  // Go to the end of the list
  while (right) {
    left = left->next;
    right = right->next;
  }

  // Delete node
  struct ListNode* temp = left->next->next;
  free(left->next);
  left->next = temp;

  return dummy.next;
}
