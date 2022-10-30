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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* barrier = new TreeNode(1001);
        int level = 0;
        q.push(barrier);
        
        while (!q.empty())
        {
            TreeNode* n = q.front();
            q.pop();
            
            if (n == nullptr)
                continue;
            
            if (n->val > 1000)
            {
                ++level;
                if (!q.empty())
                    q.push(barrier);
                continue;
            }
            
            if (levels.size() == level)
                levels.push_back(vector<int>());
            levels[level].push_back(n->val);
            q.push(n->left);
            q.push(n->right);
        }
        return levels;
    }
};