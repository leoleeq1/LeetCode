/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA;
        auto b = headB;
        auto ca = 0;
        auto cb = 0;

        while (a)
        {
            a = a->next;
            ++ca;
        }
        
        while (b)
        {
            b = b->next;
            ++cb;
        }
        
        auto diff = ca - cb;
        a = headA;
        b = headB;
        while (diff > 0)
        {
            a = a->next;
            --diff;
        }
        while (diff < 0)
        {
            b = b->next;
            ++diff;
        }
        
        while (a && b && a != b)
        {
            a = a->next;
            b = b->next;
        }
        if (a == b || a)
            return a;
        return b;
    }
};