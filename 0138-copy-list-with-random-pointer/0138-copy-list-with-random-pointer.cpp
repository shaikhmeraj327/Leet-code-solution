/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy=new Node(-1);
        Node* temp=head;
        Node* ptr=dummy;
        while(temp){
            ptr->next=new Node(temp->val);
            temp=temp->next;
            ptr=ptr->next;
        }
        unordered_map<Node*,Node*>map;
        temp=head;
        ptr=dummy->next;
        while(temp){
            map[temp]=ptr;
            ptr=ptr->next;
            temp=temp->next;
        }
        temp=head;
        ptr=dummy->next;
        while(temp){
            ptr->random=map[temp->random];
            temp=temp->next;
            ptr=ptr->next;
        }
        return dummy->next;

    }
};