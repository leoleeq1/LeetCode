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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto root = new ListNode(-1, head);
        auto prev = root;
        auto p = head;
        auto pn = head;
        
        for (int i=0;i<n;++i)
        {
            pn = pn->next;
        }
        
        while(pn)
        {
            prev = prev->next;
            p = p->next;
            pn = pn->next;
        }
        
        prev->next = p->next;
        return root->next;
    }
};