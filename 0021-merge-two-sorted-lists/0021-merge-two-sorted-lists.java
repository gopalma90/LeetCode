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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
 
    if(list1== null)
    {
      return list2;
    }
    if(list2== null)
    {
      return list1;
    }

    ListNode curr1 = list1;
    ListNode curr2 = list2;

    ListNode prev1 = null;
    ListNode prev2 = null;

/*
    while(curr1.next!=null && curr1.next.val < curr2.val )
    {
      prev1 = curr1;
      curr1 = curr1.next;
    }

    while(curr2.next!=null && curr2.next.val < curr1.val )
    {
      prev2 = curr2;
      curr2 = curr2.next;
    }
    */

    
    while(curr1 != null && curr2!= null)
    {
      if( curr1.val <= curr2.val)
      {
        while(curr1.next!= null && curr1.next.val <= curr2.val)
        {
          prev1 = curr1;
          curr1 = curr1.next;
        }
        prev1 = curr1;
        curr1 = curr1.next;
        prev1.next = curr2;
        prev2 = curr2;
         //curr2 = curr2.next;
      }
      else {
        while(curr2.next!= null && curr2.next.val < curr1.val)
        {
          prev2 = curr2;
          curr2 = curr2.next;
        }
        prev2 = curr2;
        curr2 = curr2.next;
        prev2.next = curr1;
        prev1 = curr1;
         //curr1 = curr1.next;
      }

    }

    if(list1.val <= list2.val)
      return list1;
    else return list2;
    }
}