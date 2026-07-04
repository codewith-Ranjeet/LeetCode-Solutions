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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        ListNode* head = NULL;
        int minVal = INT_MAX;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL)
                continue;
            if (lists[i]->val < minVal) {
                head = lists[i];
                minVal = lists[i]->val;
            }
        }
        ListNode* temp = head;
        while (temp != NULL) {
            minVal = INT_MAX;
            for (int i = 0; i < lists.size(); i++) {
                if (temp == lists[i])
                    lists[i] = lists[i]->next;
            }

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == NULL)
                    continue;
                if (lists[i]->val < minVal) {
                    temp->next = lists[i];
                    minVal = lists[i]->val;
                }
            }
            temp = temp->next;
        }

        return head;
    }
};