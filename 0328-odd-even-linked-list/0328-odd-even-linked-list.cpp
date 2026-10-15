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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenHead=new ListNode(-1);
        ListNode* oddHead=new ListNode(-1);
        ListNode* even=evenHead;
        ListNode* odd=oddHead;
        ListNode* ptr=head;
        int count=1;
        while(ptr){
            if(count%2==1){
                odd->next=ptr;
                odd=odd->next;
            }
            else {
                even->next=ptr;
                even=even->next;
            }
            ptr=ptr->next;
            count++;
        }
        even->next=NULL;
        odd->next=evenHead->next;
        return oddHead->next;
        
    }
};