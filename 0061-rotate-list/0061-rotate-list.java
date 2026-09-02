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
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null || head.next==null || k==0)return head;
        ListNode ptr=head;
        int n=1;
        while(ptr.next!=null){
            ptr=ptr.next;
            n++;
        }
        k=k%n;
        ptr.next=head;
        k=n-k;
        int count=0;
        while(k>0){
            ptr=ptr.next;
            k--;
        }
        head=ptr.next;
        ptr.next=null;
        return head;
    }
}