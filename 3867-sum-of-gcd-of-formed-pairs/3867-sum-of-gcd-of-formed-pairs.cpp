class Solution {
    int gcd(int a, int b){
        while(b != 0){
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        int mx = INT_MIN;
        vector<int> prefixGcd;
        for(const int x : nums){
            mx = max(mx, x);
            prefixGcd.push_back(gcd(x,mx));
        }
        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        for(int i = 0, j = n-1; i < j; i++, j--){
            sum += gcd(prefixGcd[i], prefixGcd[j]);
        }
        return sum;
    }
};