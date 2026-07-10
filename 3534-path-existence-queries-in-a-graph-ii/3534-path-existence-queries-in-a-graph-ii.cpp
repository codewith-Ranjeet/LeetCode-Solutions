/*
Core Idea:

1. Sort nodes by value.
2. From every sorted position, precompute the farthest node reachable in ONE jump.
3. Greedy fact: Jumping to the farthest reachable node always gives the minimum number of jumps.
4. Treat these greedy jumps as a functional graph.
5. Use Binary Lifting to answer each query in O(log N).

Time Complexity:
Sorting                -> O(N log N)
Build nxt[]            -> O(N)
Build Binary Lifting   -> O(N log N)
Each Query             -> O(log N)

Overall:
O((N + Q) log N)
*/

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums,
                                     int maxDiff,
                                     vector<vector<int>>& queries) {

        // Pair each value with its original node index.
        // After sorting, we'll still know which original node it belongs to.
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        // Sort nodes by their values.
        sort(a.begin(), a.end());

        // Maps:
        // original node index -> position in sorted array.
        // Queries come in original indices, but our algorithm works
        // entirely on sorted positions.
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[a[i].second] = i;

        // nxt[i] = farthest sorted index reachable from i in ONE jump.
        vector<int> nxt(n);

        // Two pointers.
        // j never moves backwards, so total preprocessing is O(n).
        int j = 0;

        for (int i = 0; i < n; i++) {

            // Expand the reachable range as much as possible.
            while (j + 1 < n &&
                   a[j + 1].first - a[i].first <= maxDiff)
                j++;

            // Greedy observation:
            // For shortest path, always jump to the farthest reachable node.
            nxt[i] = j;
        }

        // Binary lifting table.
        // up[k][i] = node reached after 2^k greedy jumps from i.
        const int LOG = 18;

        vector<vector<int>> up(LOG, vector<int>(n));

        // Base case: one jump.
        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        // Build binary lifting table.
        // Exactly same recurrence used in LCA.
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][ up[k - 1][i] ];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            // Convert original node indices into sorted positions.
            int u = pos[q[0]];
            int v = pos[q[1]];

            // Always move left -> right.
            if (u > v)
                swap(u, v);

            // Already at destination.
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int cur = u;
            int dist = 0;

            // Binary lifting:
            // Try taking the biggest possible jump first.
            // Only take it if we STILL remain before destination.
            // (Don't overshoot.)
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    dist += (1 << k);
                }
            }

            // After binary lifting, we're just before destination.
            // Check whether ONE final greedy jump reaches it.
            if (nxt[cur] >= v)
                ans.push_back(dist + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};