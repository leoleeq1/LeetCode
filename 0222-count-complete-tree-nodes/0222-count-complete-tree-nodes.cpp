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
    int getLHeight(TreeNode* n)
    {
        if (n == nullptr || n->left == nullptr)
            return 0;
        return 1 + getLHeight(n->left);
    }
    int getRHeight(TreeNode* n)
    {
        if (n == nullptr || n->right == nullptr)
            return 0;
        return 1 + getRHeight(n->right);
    }
    int dfs(TreeNode* n)
    {
        if (n == nullptr)
            return 0;
        return 1 + dfs(n->left) + dfs(n->right);
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int lh = getLHeight(root);
        int rh = getRHeight(root);
        
        int result = 0;
        if (lh == rh)
        {
            result = 1;
            for (int i=0;i<rh;++i)
            {
                result = result * 2 + 1; 
            }
        }
        else
            result = dfs(root);
        
        return result;
    }
};