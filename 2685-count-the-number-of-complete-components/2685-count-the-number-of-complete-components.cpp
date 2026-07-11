class Solution {
public:
    int find(vector<int>& path, int x) {
        if (path[x] != x)
            path[x] = find(path, path[x]);
        return path[x];
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> path(n), netEdge(n);
        unordered_map<int, int> netNode;
        for (int i = 0; i < n; i++) {
            path[i] = i;
        }
        sort(edges.begin(),edges.end());
        for (auto& e : edges) {
            if (e[0] > e[1])
                swap(e[0], e[1]);

            int p1 = find(path, e[0]);
            int p2 = find(path, e[1]);

            if (p1 != p2)
                path[p2] = p1;
            netEdge[p1]++;
        }

        for (int i = 0; i < n; i++) {
            int node1 = find(path, i);
            netNode[node1]++;
        }

        int count = 0;
        for (const auto& [key, value] : netNode) {
            int edge = ((value - 1) * value) / 2;
            if (netEdge[key] == edge)
                count++;
        }

        return count;
    }
};