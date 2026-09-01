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
   ListNode*reverselist(ListNode*head){
      ListNode*prev=NULL;
      ListNode*curr=head;
      ListNode*frwd=curr;
      while(curr!=NULL){
        frwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=frwd;
      }
      return prev;


   }
    bool isPalindrome(ListNode* head) {

       if(head->next==NULL){
        return true;
       }
       ListNode*slow=head;
       ListNode*fast=head;
       while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
       }
       ListNode*right=reverselist(slow);
       while(right!=NULL){
        if(right->val!=head->val)
         return false;
        head=head->next;
        right=right->next;
       }
       return true;




        // ListNode*ptr=head;
        // if(head->next==NULL){
        //     return true;
        // }
        // vector<int>ans;
        // while(ptr!=NULL){
        //     ans.push_back(ptr->val);
        //     ptr=ptr->next;
        // }
        // vector<int>res=ans;
        // reverse(res.begin(),res.end());
        // if(ans==res)
        //     return true;
        // return false;
        
    }
};