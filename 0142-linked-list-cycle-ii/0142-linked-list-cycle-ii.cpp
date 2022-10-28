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
    int getLoopLength(ListNode* n)
    {
        ListNode* tmp = n;
        int length = 0;
        
        do
        {
            ++length;
            tmp = tmp->next;            
        } while (tmp != n);
        
        return length;
    }
    
    ListNode* getBeginNodeOfCycle(ListNode* head, int loopLength)
    {
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i=0;i<loopLength;++i)
        {
            p2 = p2->next;
        }
        
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode* t = head;
        ListNode* r = head;
        while (t != nullptr && r != nullptr && r->next != nullptr)
        {            
            t = t->next;
            r = r->next->next;

            if (t == r)
            {
                return getBeginNodeOfCycle(head, getLoopLength(t));
            }
        }
        return nullptr;
    }
};