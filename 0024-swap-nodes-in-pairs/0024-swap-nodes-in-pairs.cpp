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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        head = head->next;
        int index = 1;

        while (temp != NULL) {
            next = temp->next;
            if (index % 2 != 0) {
                if (temp->next == NULL) {
                    temp->next = NULL;
                    return head;
                }

                if (temp->next->next != NULL) {
                    if (temp->next->next->next != NULL) {
                        temp->next = temp->next->next->next;
                    } else {
                        temp->next = temp->next->next;
                    }
                } else {
                    temp->next = NULL;
                }
            } else {
                temp->next = prev;
            }
            index++;
            prev = temp;
            temp = next;
        }
        return head;
    }
};