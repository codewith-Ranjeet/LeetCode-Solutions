class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        int prevZeros = INT_MIN;
        int best = 0;

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && s[i] == s[j])
                j++;

            int len = j - i;

            if (s[i] == '1') {
                ones += len;
            } else {
                best = max(best, prevZeros + len);
                prevZeros = len;
            }

            i = j;
        }
        return ones + best;
    }
};