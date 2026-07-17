class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) return {newInterval};

        vector<vector<int>> r;
        int i = 0;
        for (; i < n; i++) {
            if (intervals[i][1] >= newInterval[0]) {
                if (intervals[i][0] > newInterval[1]) {
                    r.push_back(newInterval);
                    newInterval[0] = -1;
                    break;
                }
                int s = min(intervals[i][0], newInterval[0]);
                while (i < n && newInterval[1] >= intervals[i][0])
                    i++;

                int e = max(intervals[--i][1], newInterval[1]);
                r.push_back({s, e});
                i++;
                newInterval[0] = -1;
                break;
            }
            r.push_back(intervals[i]);
        }

        for (; i < n; i++)
            r.push_back(intervals[i]);

        if(newInterval[0] > 0) r.push_back(newInterval);
        return r;
    }
};