/*
Leetcode #100 Same Tree
https://leetcode.com/problems/same-tree/
9 September 2025
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> pq, qq;

        pq.push(p);
        qq.push(q);

        while (!pq.empty() && !qq.empty()) {
            TreeNode* p_node = pq.front();
            pq.pop();
            TreeNode* q_node = qq.front();
            qq.pop();

            if (!p_node && !q_node) continue;
            if (!p_node || !q_node) return false;
            if (p_node->val != q_node->val) return false;

            pq.push(p_node->left);
            pq.push(p_node->right);
            qq.push(q_node->left);
            qq.push(q_node->right);
        }
        return pq.empty() && qq.empty();
    }
};