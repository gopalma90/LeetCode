/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode first = head;
    ListNode second = head;
    
    if(head.next == null && n < 2)
        return null;
   
    int i = 0;
    while( i < n )
    {
      second = second.next;
      i++;
    }
    
    if(second == null)
    {
      return first.next;
    }

    ListNode prev = null;
    while( second != null)
    {
      second = second.next;
      prev = first;
      first = first.next;
    }

    if(first != null)
      prev.next = first.next;
    
    return head;
    }
}