/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;
        
        ListNode head = null;
        ListNode node = null;
        if (list1.val < list2.val)
        {
            head = node = list1;
            list1 = list1.next;
        }
        else
        {
            head = node = list2;
            list2 = list2.next;
        }
        
        while (list1 != null && list2 != null)
        {
            if (list1.val < list2.val)
            {
                node.next = list1;
                node = list1;
                list1 = list1.next;
            }
            else
            {
                node.next = list2;
                node = list2;
                list2 = list2.next;
            }
        }
        
        if (list1 != null)
            node.next = list1;
        if (list2 != null)
            node.next = list2;
        
        return head;
    }
}