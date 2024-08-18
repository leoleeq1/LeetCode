/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> newNodes;
    bool visited[101] = {false,};
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        Node* newNode = getNodeOrCreate(node->val);
        visited[node->val] = true;
        
        for (Node* nb : node->neighbors)
        {
            Node* newNb = getNodeOrCreate(nb->val);
            newNode->neighbors.push_back(newNb);
            if (!visited[nb->val]) cloneGraph(nb);
        }
        
        return newNode;
    }
    
    Node* getNodeOrCreate(int val) {
        return newNodes.find(val) == newNodes.end()
            ? newNodes[val] = new Node(val)
            : newNodes[val];
    }
};