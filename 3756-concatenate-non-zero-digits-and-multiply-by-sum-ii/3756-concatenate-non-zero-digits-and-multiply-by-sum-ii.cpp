class Solution {
    const int M = 1000000007;

    int mul(long long x, long long y){
        return x * y % M;
    };

    void add(int &x, int y){
        if((x += y) >= M){
            x -= M;
        }
    };

    void sub(int &x, int y){
        if((x -=  y) < 0){
            x += M;
        }
    };

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        //precomputation
        vector<int> nonz(n+1), sum(n+1), x(n+1);
        for(int i = 1; i <= n; i++){
            nonz[i] = nonz[i-1];
            sum[i] = sum[i-1];
            x[i] = x[i-1];

            int c = s[i-1] - '0';
            if(c){
                nonz[i]++;
                sum[i] += c;
                add(x[i] = mul(x[i], 10), c);
            }
        }

        //power
        int m = nonz[n];
        vector<int> p(m+1);
        for(int i = p[0] = 1; i <= m; i++){
            p[i] = mul(p[i-1], 10);
        }

        //answer
        vector<int> r;
        for(const auto & q : queries){
            int temp = 0;
            sub(temp = x[q[1] + 1], mul(x[q[0]], p[nonz[q[1]+1] - nonz[q[0]]])); //substring extraction
            r.push_back(mul(temp, sum[q[1]+1] - sum[q[0]]));
        }
        return r;
    }
};