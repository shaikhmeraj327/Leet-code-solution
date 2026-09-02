/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node ptr=head;
        Node dummy=new Node(-1);
        Node temp=dummy;
        while(ptr!=null){
            temp.next=new Node(ptr.val);
            ptr=ptr.next;
            temp=temp.next;
        }
        temp=dummy.next;
        HashMap<Node,Node>map=new HashMap<Node,Node>();
        ptr=head;
        while(ptr!=null){
            map.put(ptr,temp);
            ptr=ptr.next;
            temp=temp.next;
        }
        ptr=head;
        temp=dummy.next;
        while(ptr!=null){
            temp.random=map.get(ptr.random);
            temp=temp.next;
            ptr=ptr.next;
        }
        return dummy.next;
    }
}