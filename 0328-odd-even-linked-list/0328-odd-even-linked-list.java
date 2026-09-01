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
    public ListNode oddEvenList(ListNode head) {
        if(head==null || head.next==null)return head;

        ListNode evenHead=null;
        ListNode even=null;
        ListNode oddHead=null;
        ListNode odd=null;
        ListNode ptr=head;
        int count=1;
        while(ptr!=null){
            if(count%2==0){
                if(evenHead==null){
                    evenHead=ptr;
                    even=ptr;
                }
                else{
                    even.next=ptr;
                    even=even.next;
                }
            }
            else{
                if(oddHead==null){
                    oddHead=ptr;
                    odd=ptr;
                }
                else{
                    odd.next=ptr;
                    odd=odd.next;
                }
            }
            ptr=ptr.next;
            count++;
        }
        if(even!=null)even.next=null;
        if(odd!=null){
            odd.next=evenHead;
            return oddHead;
        }
        return evenHead;
    }
}