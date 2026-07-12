class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> rank;
        vector<int> ans = arr;
        sort(arr.begin(), arr.end());

        int r = 1;
        for(int i = 0; i < n; i++){
            if(!rank.count(arr[i])) rank[arr[i]] = r++;
        }

        for(int i = 0; i < n; i++){
            ans[i] = rank[ans[i]];
        }
        return ans;
    }
};