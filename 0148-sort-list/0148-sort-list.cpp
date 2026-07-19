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
    ListNode* sortList(ListNode* head) {
        vector<int> r;
        ListNode *temp = head;

        while(temp){
            r.push_back(temp->val);
            temp = temp->next;
        }
        sort(r.begin(), r.end());

        temp = head;
        for(int i = 0; temp; temp = temp->next,i++){
            temp->val = r[i];
        }

        return head;
    }
};