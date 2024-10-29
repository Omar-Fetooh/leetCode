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
ListNode* reverseLL(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* temp = head->next;
    ListNode* back = head;
    ListNode* front = temp->next;
    back->next = nullptr;
    while (temp->next) {
        temp->next = back;
        back = temp;
        temp = front;
        front = front->next;
    }
    temp->next = back;
    return temp;
}
    bool isPalindrome(ListNode* head) {
      ListNode* slow=head;
      ListNode* fast=head;
      while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
      }
     ListNode* newHead= reverseLL(slow->next);
      ListNode* first=head;
      ListNode* second=newHead;
      while(second){
        if(first->val !=second->val){
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
      }
      reverseLL(newHead);
      return true;
    }
};

// first solution 33.34% beats
//  bool isPalindrome(ListNode* head) {
//         ListNode* temp=head;
//         string str=\\;
//         while(temp){
//             str+=temp->val;
//             temp=temp->next;
//         }
//         string cpy=str;
//         reverse(str.begin(),str.end());
//         if(cpy == str) return true;
//         return false;
    // }