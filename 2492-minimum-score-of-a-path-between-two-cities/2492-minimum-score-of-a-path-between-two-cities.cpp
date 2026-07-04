class Solution {
public:
    int find(vector<int>& rootParent, int node) {
        if (rootParent[node] != node)
            rootParent[node] = find(rootParent, rootParent[node]);
        return rootParent[node];
    }

    int minScore(int n, vector<vector<int>>& roads) {
        int minEdge = INT_MAX;
        int m = roads.size();
        vector<int> rootParent(n + 1);

        // all node start with self as parent node
        for (int i = 1; i <= n; i++) {
            rootParent[i] = i;
        }

        // DSU
        for (auto& road : roads) {
            int n1 = road[0], n2 = road[1];
            int p1 = find(rootParent, n1), p2 = find(rootParent, n2);
            if (p1 != p2)
                rootParent[p2] = p1;
        }

        int root = find(rootParent, 1);
        for (auto& road : roads) {
            if (find(rootParent, road[0]) == root)
                minEdge = min(minEdge, road[2]);
        }
        return minEdge;
    }
};