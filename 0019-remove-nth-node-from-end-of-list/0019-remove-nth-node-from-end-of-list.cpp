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
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* frwd=head;
        while(frwd){
            frwd=frwd->next;
            curr->next=prev;
            prev=curr;
            curr=frwd;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr=reverse(head);
        int count=1;
        ListNode*prev=NULL;
        ListNode* curr=ptr;
        while(curr && count<n){
              prev=curr;
              curr=curr->next;
              count++;
        }
        if(curr==ptr){
            ptr=ptr->next;
            curr->next=NULL;
            delete curr;
            return ptr=reverse(ptr);
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return ptr=reverse(ptr);
    }
};