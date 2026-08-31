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
        if(!(head->next->next && head->next->next->next)) return {-1, -1};

        vector<int> idx;

        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *next = head->next->next;

        int pos = 2;

        while(next){
            if((curr->val < prev->val && curr->val < next->val) || 
            (curr->val > prev->val && curr->val > next->val)){
                idx.push_back(pos);
            }
            next = next->next;
            curr = curr->next;
            prev = prev->next;
            pos++;
        }

        if(idx.size() < 2) return {-1, -1};

        int minDist = INT_MAX;
        for(int i = 1; i < idx.size(); i++){
            minDist = min(minDist, idx[i] - idx[i-1]);
        }

        return {minDist, idx[idx.size() - 1] - idx[0]};
    }
};