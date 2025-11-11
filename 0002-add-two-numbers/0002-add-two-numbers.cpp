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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        ListNode* newHead = new ListNode(sum % 10);
        l1 = l1->next;
        l2 = l2->next;
        sum /= 10;
        ListNode* last = newHead;
        while (l1 && l2) {
            sum += l1->val + l2->val;
            ListNode* temp = new ListNode(sum % 10);
            sum /= 10;
            last->next = temp;
             last = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            sum+= l1->val;
            ListNode* temp = new ListNode(sum % 10);
            sum /= 10;
            last->next = temp;
             last = temp;
            l1 = l1->next;
        }
        while (l2) {
            sum+= l2->val;
            ListNode* temp = new ListNode(sum % 10);
            sum /= 10;
            last->next = temp;
             last = temp;
            l2 = l2->next;
        }
        if(sum){
             ListNode* temp = new ListNode(sum % 10);
            sum /= 10;
            last->next = temp;
        }
        return newHead;
    };
};