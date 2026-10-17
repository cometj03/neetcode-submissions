/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 int M = -1e9;

int foo(root) {
  if (!root) return 0;
  int left = max(0, foo(root.left));
  int right = max(0, foo(root.right));
  int val = root.val + left + right;
  M = max(M, val);
  return max(left+node.val, right+node.val, node.val);
}
 */

class Solution {
public:
    int M = -1e9;
    int foo(TreeNode* root) {
        if (!root) return 0;
        int left = max(0, foo(root->left));
        int right = max(0, foo(root->right));
        M = max(M, root->val + left + right);
        return root->val + max({left, right, 0});
    }
    int maxPathSum(TreeNode* root) {
        return max(M, foo(root));
    }
};
