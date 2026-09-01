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
    ListNode* merged(ListNode*&left,ListNode*&right){
        ListNode*dummy=new ListNode(-1);
        ListNode* ptr=dummy;
        while(left!=NULL && right!=NULL){
            if(left->val>=right->val){
                ptr->next=right;
                ptr=ptr->next;
                right=right->next;
            }
            else{
                ptr->next=left;
                ptr=ptr->next;
                left=left->next;
            }
        }
        if(left!=NULL){
            ptr->next=left;
        }
        if(right!=NULL){
            ptr->next=right;
        }
        ListNode*ans=dummy->next;
        delete dummy;
        return ans;
    }
    ListNode* findMid(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*left=head;
        ListNode*mid=findMid(head);
        ListNode*right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        ListNode*ans=merged(left,right);
        return ans;

        
    }
};