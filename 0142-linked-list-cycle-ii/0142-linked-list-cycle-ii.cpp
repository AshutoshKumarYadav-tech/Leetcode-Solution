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
    ListNode *detectCycle(ListNode *head) {
        /*map<ListNode*,int>m;
        ListNode* temp=head;
        while(temp){
            if(m.find(temp)==m.end())
              {
                m[temp]==0;  
              }
            else{
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;  */ 


    ListNode* slow=head;
    ListNode* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
            slow =slow->next;
            fast=fast->next;
            }
        return slow;
        }
    }
    return nullptr;
    }
};