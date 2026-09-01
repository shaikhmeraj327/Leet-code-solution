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
        ListNode curr=head;
        ListNode prev=null;
        ListNode frwd=head;
        while(frwd!=null){
            frwd=frwd.next;
            curr.next=prev;
            prev=curr;
            curr=frwd;
        }
        return prev;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null || head.next==null)return null;
        head=reverse(head);
        int count=1;
        ListNode prev=null;
        ListNode ptr=head;
        while(ptr!=null && count<n){
            count++;
            prev=ptr;
            ptr=ptr.next;
        }
        if(ptr.next==null){
            prev.next=null;
            head=reverse(head);
            return head;
        }
        if(count==1)return head=reverse(head.next);
        prev.next=ptr.next;
        ptr.next=null;
        head=reverse(head);
        return head;


    }
}




