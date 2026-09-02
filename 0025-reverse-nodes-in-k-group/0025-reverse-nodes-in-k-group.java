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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null)return head;
        ListNode temp=head;
        int count=0;
        while(temp!=null && count<k){
            temp=temp.next;
            count++;
        }
        if(count<k)return head;
        ListNode prev=null;
        ListNode frwd=head;
        ListNode curr=head;
        count=1;
        while(frwd!=null && count<=k){
             frwd=frwd.next;
             curr.next=prev;
             prev=curr;
             curr=frwd;
             count++;
        }
        if(frwd!=null){
            head.next=reverseKGroup(frwd,k);
        }
        return prev;
    }
}