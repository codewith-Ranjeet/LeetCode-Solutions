class Solution {
public:
    int find(vector<int>& parent, int node) {
        if (parent[node] != node) {
            parent[node] = find(parent, parent[node]);
        }
        return parent[node];
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        int m = nums.size();
        vector<int> parent(m);
        for (int i = 0; i < m; i++)
            parent[i] = i;

        for (int i = 0, j = 1; j < m;) {
            if (abs(nums[i] - nums[j]) <= maxDiff) {
                parent[j] = i;
                j++;
            } else {
                i++;
                if (i == j)
                    j++;
            }
        }

        vector<bool> r;
        for (const auto& q : queries) {
            r.push_back(find(parent, q[0]) == find(parent, q[1]));
        }
        return r;
    }
};