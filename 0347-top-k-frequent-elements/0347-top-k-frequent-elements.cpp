class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        
        vector<vector<int>> bucket(n+1);
        for(auto &[key, val] : freq){
            bucket[val].push_back(key);
        }
        
        vector<int> res;
        for(int i = n; i >= 0 && res.size() < k; i--){
            for(int num : bucket[i]) res.push_back(num);
        }
        return res;
    }
};