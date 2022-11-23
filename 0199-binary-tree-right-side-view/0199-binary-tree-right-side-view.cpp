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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return vector<int>();
        
        vector<int> result;
        queue<TreeNode*> q[2];
        q[0].push(root);
        
        int h = 0;
        int i=0,j=1;
        while (!q[i].empty())
        {
            result.push_back(q[i].front()->val);
            while (!q[i].empty())
            {
                auto n = q[i].front();
                q[i].pop();
                if (n->right != nullptr)
                    q[j].push(n->right);
                if (n->left != nullptr)
                    q[j].push(n->left);
            }
            ++h;
            swap(i,j);
        }
        
        return result;
    }
};