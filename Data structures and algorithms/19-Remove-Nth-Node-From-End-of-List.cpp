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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode* front=head;
        ListNode* temp=nullptr;
        ListNode* back=nullptr;
        while(n--) front=front->next;
        temp=head;
        if(temp==head->next) back=head;
        while(front){
            front=front->next;
            temp=temp->next;
            back=(temp==head->next)?head:back->next;
        }
        if (back == NULL) return temp->next;
        back->next= temp->next ?temp->next: nullptr;
        temp->next=nullptr;
        delete temp;
     return head;   
    }
};