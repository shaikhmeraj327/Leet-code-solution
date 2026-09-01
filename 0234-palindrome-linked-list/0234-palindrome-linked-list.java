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
    public ListNode reverse(ListNode slow){
        ListNode frwd=slow;
        ListNode prev=null;
        ListNode curr=slow;
        while(frwd!=null){
            frwd=frwd.next;
            curr.next=prev;
            prev=curr;
            curr=frwd;
        }
        return prev;
    }

    public boolean isPalindrome(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;
        if(head==null || head.next==null)return true;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        slow=reverse(slow);
        while(slow!=null){
            if(slow.val!=head.val)return false;
            slow=slow.next;
            head=head.next;
        }
        return true;
    }
}