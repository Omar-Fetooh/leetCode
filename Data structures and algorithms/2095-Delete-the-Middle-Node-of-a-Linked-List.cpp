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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL) return NULL;
      ListNode* slow=head;
      ListNode* fast=head;
      ListNode* temp=head;
      while(fast&&fast->next) {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
      }  
    //   while(temp->next!=slow) temp=temp->next;
      temp->next=slow->next;
      slow->next=nullptr;
      delete slow;
      return head;
    }
};