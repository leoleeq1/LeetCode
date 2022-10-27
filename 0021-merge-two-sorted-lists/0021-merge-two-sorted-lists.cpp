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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* last;
        ListNode* tmp;
        while (list1 != nullptr && list2 != nullptr)
        {
            tmp = list1->val < list2->val ? list1 : list2;
            if (head == nullptr)
            {
                head = tmp;
                last = head;
            }
            else
            {
                last->next = tmp;
                last = last->next;
            }
            
            if (tmp == list1)
            {
                list1 = list1->next;
            }
            else
            {
                list2 = list2->next;
            }
        }
        
        tmp = list1 == nullptr ? list2 : list1;
        if (head == nullptr)
        {
            head = tmp;
        }
        else
        {
            last->next = tmp;
        }
        return head;
    }
};