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
    ListNode* partition(ListNode* head, int x) {
        ListNode* r1 = new ListNode(-1);
        ListNode* r2 = new ListNode(-1);
        ListNode* p1 = r1;
        ListNode* p2 = r2;
        ListNode* cur = head;
        
        while (cur)
        {
            if (cur->val < x)
            {
                p1->next = cur;
                p1 = p1->next;
            }
            else
            {
                p2->next = cur;
                p2 = p2->next;
            }
            
            ListNode* tmp = cur->next;
            cur->next = nullptr;
            cur = tmp;
        }
        
        p1->next = r2->next;
        return r1->next;
    }
};