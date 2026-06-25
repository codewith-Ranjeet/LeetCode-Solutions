class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int freq = 0;
            for(int j = i; j < n; j++){
                freq += (nums[j] == target)? 1 : -1;
                ans += (freq > 0);
            }
        }
        return ans;
    }
};