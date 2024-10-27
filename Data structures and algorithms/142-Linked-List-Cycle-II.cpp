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
      ListNode* slow=head;
      ListNode* fast=head;
      while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
      }
      return NULL;
    }
};

// First approach
//   map<ListNode* ,int>mp;
//         ListNode* temp=head;
//         int pos=0;
//         while(temp){
//             if(mp.count(temp)>0) return temp;
//             mp[temp]=pos++;
//             temp=temp->next;
//         }
//         return NULL;