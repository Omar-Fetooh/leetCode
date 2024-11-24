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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* t1 = headA;
    ListNode* t2 = headB;
    while (t1!=t2) {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2) return t1;  // could return collision point or null 

        if (t1 == NULL) t1 = headB;
        if (t2 == NULL) t2 = headA;
    }
    return t1;
    }
};

// my initial code 
    //  vector<ListNode*>v;
    // while (headA) {
    //     v.push_back(headA);
    //     headA = headA->next;
    // }
    // while (headB)
    // {
    //     if (find(v.begin(),v.end(),headB)!=v.end()) {
    //         return headB;
    //     }
    //     headB = headB->next;
    // }
    // return NULL;