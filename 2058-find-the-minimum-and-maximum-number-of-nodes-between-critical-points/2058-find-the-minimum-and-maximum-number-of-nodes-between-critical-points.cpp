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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!(head->next->next && head->next->next->next))
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;

        int pos = 2, s = -1, e = -1, c = -1, minDist = INT_MAX;

        while (next) {
            if ((curr->val < prev->val && curr->val < next->val) ||
                (curr->val > prev->val && curr->val > next->val)) {
                if (s == -1) {
                    s = pos;
                    e = pos;
                    next = next->next;
                    curr = curr->next;
                    prev = prev->next;
                    pos++;
                    continue;
                }
                c = e;
                e = pos;

                minDist = min(minDist, e - c);
            }
            next = next->next;
            curr = curr->next;
            prev = prev->next;
            pos++;
        }

        if (c == -1)
            return {-1, -1};

        return {minDist, e - s};
    }
};