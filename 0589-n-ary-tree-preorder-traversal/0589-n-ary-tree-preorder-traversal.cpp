/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node*> s;
        s.push(root);
        
        while (!s.empty())
        {
            Node* n = s.top();
            s.pop();
            
            if (n == nullptr)
                continue;
            
            result.push_back(n->val);
            for (int i=n->children.size() - 1;i>=0;--i)
                s.push(n->children[i]);
        }
        return result;
    }
};