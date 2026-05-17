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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        int cnt = 1;
        ListNode* curr = head;
        ListNode* newHead = NULL;
        ListNode* last = NULL;
        stack<ListNode*> st;
        ListNode* currHead;
        st.push(head);
        while (curr != NULL) {
            while (cnt < k && curr->next) {
                curr = curr->next;
                ++cnt;
                st.push(curr);
            }
            ListNode* future;
            if (cnt == k) {
                if (newHead == NULL) {
                    newHead = curr;
                }
                currHead = curr;
                future = curr->next;
                st.pop();
                while (!st.empty()) {
                    ListNode* temp = st.top();
                    st.pop();
                    curr->next = temp;
                    curr = temp;
                }
                if (last)
                    last->next = currHead;
                curr->next = future;
                last = curr;
                curr = future;
                st.push(future);
                cnt = 1;
            } else
                break;
        }
        return newHead;
    }
};