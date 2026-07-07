class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        long long sum = 0;
        string num = "";

        for(char c : to_string(n)){
            if(c == '0') continue;
            sum += (c - '0');
            num += c;
        }
        return stoi(num) * sum;
    }
};