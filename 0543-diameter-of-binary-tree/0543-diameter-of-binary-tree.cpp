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
    int diameterOfBinaryTree(TreeNode* root) {
        dp(root);
        return maxDia;
    }
    
    int dp(TreeNode* node)
    {
        if (!node)
            return -1;
        
        auto l = dp(node->left) + 1;
        auto r = dp(node->right) + 1;
        maxDia = max(maxDia, l + r);
        return max(l, r);
    }
private:
    int maxDia = 0;
};