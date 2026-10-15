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
    ListNode* solve(ListNode* head){
        if(head==NULL)return NULL;
        ListNode* frwd=head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(frwd){
            frwd=frwd->next;
            curr->next=prev;
            prev=curr;
            curr=frwd;
        }
        return prev;
    }

    ListNode* reverseList(ListNode* head) {
       head= solve(head); 
       return head;
    }
};