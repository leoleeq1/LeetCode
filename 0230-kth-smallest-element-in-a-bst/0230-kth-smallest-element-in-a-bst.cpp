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
    int i=0;
    int tree[10000];
    void iterate(TreeNode* n)
    {
        if (n->left != nullptr)
        {
            iterate(n->left);
        }
        tree[i++] = n->val;
        if (n->right != nullptr)
        {
            iterate(n->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        iterate(root);
        return tree[k - 1];
    }
};