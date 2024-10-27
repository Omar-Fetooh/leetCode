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
    bool hasCycle(ListNode *head) {
     ListNode* slow=head;
     ListNode* fast=head;
     ListNode* temp=head;
     while( fast !=NULL&&fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
     }
     return false;
    }
};

//  MY first Approach
//    set<ListNode*>st;
//         ListNode* temp=head;
//         while(temp){
//             st.insert(temp);
//             temp=temp->next;
//             if(st.count(temp)!=0) return true;
//         }
//         return false;