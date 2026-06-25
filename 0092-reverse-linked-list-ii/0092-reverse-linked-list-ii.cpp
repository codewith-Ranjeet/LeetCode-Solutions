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
    ListNode* reverseNode(ListNode* head, int diff) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* temp = head;
        for (int i = 0; i <= diff; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        temp->next = curr;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right == 1)
            return head;
        if (left == 1) {
            head = reverseNode(head, right - left);
            return head;
        }
        ListNode* temp = head;

        for (int i = 1; i < left - 1; i++) {
            temp = temp->next;
        }
        ListNode* leftPrev = reverseNode(temp->next, right - left);
        temp->next = leftPrev;

        return head;
    }
};