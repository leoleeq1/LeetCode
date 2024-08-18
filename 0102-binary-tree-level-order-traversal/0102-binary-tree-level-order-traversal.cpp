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
        vector<vector<int>> answer;
        if (root == nullptr) return answer;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        vector<int> level;
        while (!q.empty())
        {
            auto node = q.front(); q.pop();
            if (node == nullptr)
            {
                answer.push_back(level);
                level.clear();
                if (!q.empty()) q.push(nullptr);
                continue;
            }
            
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        return answer;
    }
};