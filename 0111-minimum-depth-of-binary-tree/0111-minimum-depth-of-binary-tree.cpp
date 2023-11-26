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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int d = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            ++d;
            auto cnt = q.size();
            for (auto i=0;i<cnt;++i)
            {
                auto n = q.front();
                q.pop();
                if (!n->left && !n->right)
                    return d;
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
        }
        return d;
    }
};