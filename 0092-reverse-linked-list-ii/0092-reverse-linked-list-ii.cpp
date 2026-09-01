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
   ListNode* reverse(ListNode* head){
    ListNode* frwd=head;
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(frwd){
        frwd=frwd->next;
        curr->next=prev;
        prev=curr;
        curr=frwd;
    }
    return prev;
   }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right)return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* beforeLeft=dummy;
        for(int i=1;i<left;i++){
            beforeLeft=beforeLeft->next;
        }
        ListNode* leftPtr=beforeLeft->next;
        ListNode* rightPart=dummy;
        
        for(int i=1;i<=right;i++){
            rightPart=rightPart->next;
        }
        ListNode* rightAfter=rightPart->next;
        rightPart->next=NULL;
        beforeLeft->next=reverse(leftPtr);
        while(beforeLeft->next)beforeLeft=beforeLeft->next;
        beforeLeft->next=rightAfter;
        head=dummy->next;
        dummy->next=NULL;
        delete dummy;
        return head;

    }
};