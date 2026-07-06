class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int remaining = n;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        for(int i = 0, j = 1; j < n; j++){
            int a = intervals[i][1];
            int b = intervals[j][1];

            if(a >= b){
                remaining--;
            } else {
                i = j;
            }
        }
        return remaining;
    }
};