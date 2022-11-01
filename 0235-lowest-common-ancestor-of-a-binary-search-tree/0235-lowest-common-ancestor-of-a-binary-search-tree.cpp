/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        s.push(root);
        
        if (p->val > q->val)
        {
            TreeNode* tmp = p;
            p = q;
            q = tmp;
        }
        
        while (!s.empty())
        {
            TreeNode* n = s.top();
            s.pop();
            
            if (n == nullptr)
                continue;
            
            if (q->val == n->val)
            {
                return n;
            }
            else if (p->val < n->val && q->val < n->val)
            {
                s.push(n->left);
            }
            else if (p->val > n->val && q->val > n->val)
            {
                s.push(n->right);
            }
            else
            {
                return n;
            }
        }
        
        return nullptr;
    }
};