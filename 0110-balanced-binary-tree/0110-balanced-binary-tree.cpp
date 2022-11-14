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
 */
class Solution {
public:
    int getHeight(TreeNode* n)
    {
        if (n == nullptr)
            return 0;
        if (n->left == nullptr && n->right == nullptr)
            return 1;
        return 1 + max(getHeight(n->left), getHeight(n->right));
        
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};