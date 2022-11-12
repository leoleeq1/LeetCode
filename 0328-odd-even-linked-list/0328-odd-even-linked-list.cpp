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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* o = head;
        ListNode* e = head->next;
        ListNode* no, *t1, *t2;
        while (e != nullptr && e->next != nullptr)
        {
            no = e->next;
            t1 = o->next;
            t2 = no->next;
            o->next = no;
            no->next = t1;
            e->next = t2;
            o = no;
            e = t2;
        }
        return head;
    }
};