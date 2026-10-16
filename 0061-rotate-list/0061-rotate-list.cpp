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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head;
        if(head==NULL)return NULL;
        int count=1;
        while(curr->next ){
            count++;
            curr=curr->next;
        }
        k=k%count;
        k=count-k;
        curr->next=head;
        while(k>0){
            curr=curr->next;
            k--;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};