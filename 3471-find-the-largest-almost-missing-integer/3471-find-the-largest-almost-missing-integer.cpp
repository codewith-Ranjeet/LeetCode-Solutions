class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) return *max_element(nums.begin(), nums.end());
        if(k == 1) {
            unordered_map<int, int> freq;
            for(int x : nums) freq[x]++;
            int large = -1;
            for(auto &[key, value] : freq){
                if(value == 1) large = max(large, key);
            }
            return large;
        }

        int first = nums[0], last = nums[n - 1];

        if(first == last) return -1;
        for(int i = 1; i < n - 1; i++){
            if(nums[i] == first) first = -1;
            if(nums[i] == last) last = -1;
        }

        return max(first, last);
    }
};