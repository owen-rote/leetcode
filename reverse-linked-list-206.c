/*
Leetcode #206 Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/
4 November 2024
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  struct ListNode* left = head;
  struct ListNode* right = head;

  while (right != NULL) {
    if (left == right) {
      right = right->next;
      left->next = NULL;
      head = right;
      continue;
    }
    // Go through forward and switch the pointer to previous
    struct ListNode* temp = right->next;
    right->next = left;
    left = right;
    right = temp;
    head = right != NULL ? right : head;
  }

  // DEBUG: Print list
  // struct ListNode* it = head;
  // while (it != NULL) {
  //     printf("%d ", it->val);
  //     it = it->next;
  // }
  return head;
}