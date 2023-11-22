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
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        
        auto merged = merge2List(lists[0], lists[1]);
        if (lists.size() == 2)
            return merged;
        
        ListNode* root = new ListNode(-1, merged);
        for (int i=2;i<lists.size();++i)
        {
            merged = merge2List(root->next, lists[i]);
            root->next = merged;
        }
        
        return root->next;
    }
    
    ListNode* merge2List(ListNode* l1, ListNode* l2)
    {
        ListNode* root = new ListNode(-1);
        ListNode* p = root;
        auto p1 = l1;
        auto p2 = l2;

        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            
            p = p->next;
        }

        if (p1)
            p->next = p1;
        if (p2)
            p->next = p2;
        
        return root->next;
    }
};