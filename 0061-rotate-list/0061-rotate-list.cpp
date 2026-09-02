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
        int count=1;
        if(head==NULL || head->next==NULL)return head;
        ListNode* curr=head;
        while(curr->next){
            curr=curr->next;
            count++;
        }
        k=k%count;
        k=count-k;// do left rotation ehich will be similiar to right rotation
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



