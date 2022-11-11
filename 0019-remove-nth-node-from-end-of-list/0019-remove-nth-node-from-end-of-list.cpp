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
    ListNode* removeNthFromEnd(ListNode* head, int m) {
        queue<ListNode*> q;
        ListNode* n = head;
        while (n != nullptr)
        {
            q.push(n);
            if (q.size() > (m + 1))
            {
                q.pop();
            }
            n = n->next;
        }
        
        ListNode* front = q.front();
        if (q.size() == m)
            return front->next;
        
        q.pop();
        if (q.empty())
            front->next = nullptr;
        else
        {
            n = q.front();
            front->next = n->next;
        }
        return head;
    }
};