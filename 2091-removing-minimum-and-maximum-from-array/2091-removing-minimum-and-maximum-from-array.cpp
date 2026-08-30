class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int m = INT_MAX;
        int M = INT_MIN;

        for(int x : nums){
            m = min(m, x);
            M = max(M, x);
        }
        int d1 = 0, d2 = 0, d3 = 0;
        for(int x : nums){
            if(x == m || x == M){
                d1 = d2;
                d2 = d3;
                d3 = 0;
                continue;
            }
            d3++;
        }

        if(d1 >= d2 && d1 >= d3){
            d1 = 0;
        } else if(d2 >= d1 && d2 >= d3){
            d2 = 0;
        } else {
            d3 = 0;
        }

        return 2 + d1 + d2 + d3;
    }
};