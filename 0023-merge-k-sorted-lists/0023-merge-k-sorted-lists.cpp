/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto root = new ListNode(-1);
        auto p = root;
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq([](auto l, auto r) { return l->val > r->val; });
        
        for (auto l : lists)
        {
            if (l)
                pq.push(l);
        }
        
        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            p->next = node;
            if (node->next)
                pq.push(node->next);
            p = p->next;
        }
        
        return root->next;
    }
};