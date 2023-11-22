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
    ListNode* deleteDuplicates(ListNode* head) {
        auto slow = head;
        auto fast = head;
        
        while (fast)
        {
            if (slow->val != fast->val)
            {
                slow->next = fast;
                slow = fast;
            }
            else
                fast = fast->next;
        }
        if (slow)
            slow->next = fast;
        return head;
    }
};