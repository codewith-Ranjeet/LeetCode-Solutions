class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> r;

        for (auto& current : intervals) {
            // current completely before newInterval
            if (current[1] < newInterval[0])
                r.push_back(current);

            // newInterval completely before current
            else if (newInterval[1] < current[0]) {
                r.push_back(newInterval);
                newInterval = current;
            }

            // overlapping
            else {
                newInterval[0] = min(current[0], newInterval[0]);
                newInterval[1] = max(current[1], newInterval[1]);
            }
        }

        r.push_back(newInterval);
        return r;
    }
};