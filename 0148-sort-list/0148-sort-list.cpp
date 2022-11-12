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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* head;
        ListNode* tail;
        if (l1->val < l2->val)
        {
            tail = l1;
            l1 = l1->next;
        }
        else
        {
            tail = l2;
            l2 = l2->next;
        }
        head = tail;
        
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if (l1 != nullptr)
            tail->next = l1;
        else if (l2 != nullptr)
            tail->next = l2;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* tmp;
        ListNode* r = head;;
        ListNode* t = head;
        while (t != nullptr)
        {
            tmp = r;
            r = r->next;
            t = t->next;
            if (t != nullptr)
                t = t->next;
        }
        
        tmp->next = nullptr;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(r);
        return merge(l1, l2);
    }
};