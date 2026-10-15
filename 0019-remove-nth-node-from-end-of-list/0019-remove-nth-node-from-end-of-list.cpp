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
        ListNode* frwd=head;
        ListNode* curr=head;
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
        head=ptr;
        if(head==NULL || head->next==NULL)return NULL;
        int count=1;
        ListNode* prev=NULL;
        while(ptr && count<n){
            prev=ptr;
            ptr=ptr->next;
            count++;
        }
        if(prev==NULL){
            ptr=ptr->next;
            ptr=reverse(ptr);
            return ptr;
        }
        prev->next=ptr->next;
        ptr->next=NULL;
        head=reverse(head);
        return head;

    }
};