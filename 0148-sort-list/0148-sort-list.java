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
   public ListNode merge(ListNode left,ListNode right){
      ListNode dummy=new ListNode(0);
      ListNode ptr=dummy;
      while(left!=null && right!=null){
        if(left.val>=right.val){
            ptr.next=right;
            ptr=ptr.next;
            right=right.next;
        }
        else{
            ptr.next=left;
            ptr=ptr.next;
            left=left.next;
        }
      }
      while(left!=null){
        ptr.next=left;
        left=left.next;
        ptr=ptr.next;
      }
      while(right!=null){
        ptr.next=right;
        right=right.next;
        ptr=ptr.next;
      }
      return dummy.next;
   }

    public ListNode findMid(ListNode head){
        ListNode slow=head;
        ListNode fast=head.next;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode left=head;
        ListNode mid=findMid(head);
        ListNode right=mid.next;
        mid.next=null;
        left=sortList(left);
        right=sortList(right);
        ListNode ans=merge(left,right);
        return ans;

    }
}