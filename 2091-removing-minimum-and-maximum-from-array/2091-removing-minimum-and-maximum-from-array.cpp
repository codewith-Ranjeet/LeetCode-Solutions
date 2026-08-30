class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = INT_MAX, mx = INT_MIN;
        int mnIdx = -1, mxIdx = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < mn) {
                mn = nums[i];
                mnIdx = i;
            }

            if (nums[i] > mx) {
                mx = nums[i];
                mxIdx = i;
            }
        }

        if (mnIdx > mxIdx)
            swap(mnIdx, mxIdx);

        return min({mxIdx + 1, n - mnIdx, mnIdx + 1 + n - mxIdx});
    }
};