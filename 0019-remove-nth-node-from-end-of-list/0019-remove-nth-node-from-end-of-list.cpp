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
        int sz = 0;
        ListNode* curr = head;
        while (curr) {
            sz++;
            curr = curr->next;
        }
        int i = 1;
        curr = head;
        ListNode* prev = head;
        if (n == sz)
            return head->next;
        while (i != sz - n + 1) {
            prev = curr;
            curr = curr->next;
            ++i;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        return head;
    }
};