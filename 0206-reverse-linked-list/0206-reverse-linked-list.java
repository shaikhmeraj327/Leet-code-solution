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
    public ListNode reverse(ListNode head){
        ListNode frwd=head;
        ListNode curr=head;
        ListNode prev=null;
        while(frwd!=null){
            frwd=frwd.next;
            curr.next=prev;
            prev=curr;
            curr=frwd;
        }
        return prev;
    }
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null)return head;
        head=reverse(head);
        return head;
    }
}