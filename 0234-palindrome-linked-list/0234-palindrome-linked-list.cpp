class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr)
            return true;
        
        ListNode* n = head, *m = head;
        while (m->next != nullptr)
        {
            n = n->next;
            m = m->next;
            if (m->next != nullptr)
                m = m->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* t = nullptr;
        while (n != nullptr)
        {
            t = n->next;
            n->next = prev;
            prev = n;
            n = t;
        }
        
        while (m != nullptr)
        {
            if (head->val != m->val)
                return false;
            head = head->next;
            m = m->next;
        }
        return true;
    }
};