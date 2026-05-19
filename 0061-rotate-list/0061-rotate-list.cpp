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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        int cnt = 0;
        ListNode* curr = head;
        while (curr) {
            ++cnt;
            curr = curr->next;
        }
        k = k % cnt;
        ListNode* newHead = head;
        for (int i = 0; i < k; i++) {
            ListNode* last = newHead;
            ListNode* prev = NULL;
            while (last->next) {
                prev = last;
                last = last->next;
            }
            last->next = newHead;
            prev->next = NULL;
            newHead = last;
        }
        return newHead;
    }
};