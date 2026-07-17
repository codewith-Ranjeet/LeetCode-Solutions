class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> r;
        int s = intervals[0][0], e = intervals[0][1];
        for(const auto & i : intervals){
            if(i[0] <= e) e = max(e, i[1]);
            else {
                r.push_back({s,e});
                s = i[0];
                e = i[1];
            }
        }
        r.push_back({s,e});

        return r;
    }
};