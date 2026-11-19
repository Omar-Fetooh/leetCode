
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* back = head;
        ListNode* current = head->next;
        int pos = 1;
        vector<int> special;

        while (current && current->next) {
            if ((back->val > current->val && current->next->val > current->val) ||
                (back->val < current->val && current->next->val < current->val)) {
                special.push_back(pos);
            }

            back = current;
            current = current->next;
            pos++;
        }

        if (special.size() < 2)
            return {-1, -1};

        int mini = INT_MAX;

        for (int i = 1; i < special.size(); i++) {
            mini = min(mini, special[i] - special[i - 1]);
        }

        int maxi = special.back() - special.front();

        return {mini, maxi};
    }
};
