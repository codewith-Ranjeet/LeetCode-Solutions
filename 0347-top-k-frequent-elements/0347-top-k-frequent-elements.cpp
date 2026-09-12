class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        vector<pair<int,int>> hash(freq.begin(), freq.end());

        sort(hash.begin(), hash.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(hash[i].first);

        return res;
    }
};