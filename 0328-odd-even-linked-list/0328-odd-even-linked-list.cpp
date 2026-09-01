/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //efficient method( space o(1))
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        ListNode*odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=even;
        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;
             even->next=odd->next;
             even=even->next;
        }
        odd->next=evenHead;
        return head;
     

    }





    // void insertAtTail(ListNode*&tail,int data){
    //     ListNode*temp=new ListNode(data);
    //     tail->next=temp;
    //     tail=tail->next;
    // }
    // ListNode* oddEvenList(ListNode* head) {
    //     if(head==NULL || head->next==NULL || head->next->next==NULL){
    //         return head;
    //     }
    //     ListNode*ptr=head;
    //     ListNode*dummyNode=new ListNode(-1);
    //     ListNode*dummyHead=dummyNode;
    //     ListNode*dummyTail=dummyNode;
    //     while(ptr!=NULL){
    //         insertAtTail(dummyTail,ptr->val);
    //         if (ptr->next != NULL) {
    //             ptr = ptr->next->next;
    //         } else {
    //             break;
    //         }
    //     }
    //     ptr=head->next;
    //     while(ptr!=NULL){
    //         insertAtTail(dummyTail,ptr->val);
    //         if (ptr->next != NULL) {
    //             ptr = ptr->next->next;
    //         } else {
    //             break;
    //         }
    //     }
    //     dummyHead=dummyNode->next;
    //     delete dummyNode;
    //     return dummyHead;

        
    // }
};