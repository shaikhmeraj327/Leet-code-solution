/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isCycle(ListNode *head,ListNode*&slow,ListNode*&fast){
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        int count = 0;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        if(isCycle(head,slow,fast)){
            slow=head;
        
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
                count++;
            }
            slow->val=count;
            slow->next==NULL;
            return slow;
        }
        // slow->val=-1;
        // slow->next=NULL;
        return NULL;
    }
};