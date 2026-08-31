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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL)return {-1,-1};
        vector<int>temp;
        int count=2;
        ListNode* ptr1=head;
        ListNode* ptr2=head->next;
        ListNode*ptr3=head->next->next;
        while(ptr3){
            if(ptr2->val>ptr1->val && ptr2->val>ptr3->val)temp.push_back(count);
            else if(ptr2->val<ptr1->val && ptr2->val<ptr3->val)temp.push_back(count);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
            count++;
        }
        
        if(temp.size()<2)return {-1,-1};
        int n=temp.size();
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            mini=min(mini,temp[i]-temp[i-1]);
        }
        return {mini,temp[n-1]-temp[0]};

    }
};