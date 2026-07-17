class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        const int N = *max_element(nums.begin(), nums.end());
        vector<long long> p(N + 1);
        
        //number of element divisibile by divisor
        for (int x : nums) {
            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    p[i]++;
                    if (x / i != i)
                        p[x / i]++;
                }
            }
        }
        //pairs
        for(int i = N; i ; i--){
            p[i] = p[i] * (p[i] - 1) / 2;
            if(p[i]){
                for(int j = i + i; j <= N; j += i)
                    p[i] -= p[j];
            }
        }
        //prefix sum
        for(int i = 1; i <= N; i++) p[i] += p[i-1];
        
        vector<int> r;
        for(long long q : queries){
            r.push_back(distance(p.begin(), upper_bound(p.begin(), p.end(), q)));
        }
        return r;
    }
};