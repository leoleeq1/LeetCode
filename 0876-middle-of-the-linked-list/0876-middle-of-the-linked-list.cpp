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
    ListNode* middleNode(ListNode* head) {
        ListNode* m = head;
        ListNode* t = head->next;
        while (t != nullptr)
        {
            m = m->next;
            t = t->next == nullptr ? t->next : t->next->next;
        }
        return m;
    }
};