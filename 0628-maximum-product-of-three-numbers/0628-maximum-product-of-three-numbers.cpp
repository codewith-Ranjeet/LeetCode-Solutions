class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m1 = INT_MIN, m2, n1 = INT_MAX;
        int m3 = m2 = m1, n2 = n1;

        for (const int x : nums) {
            if (x <= n1) {
                n2 = n1;
                n1 = x;
            } else if (x <= n2) {
                n2 = x;
            }
            if (x >= m1) {
                m3 = m2;
                m2 = m1;
                m1 = x;
            } else if (x >= m2) {
                m3 = m2;
                m2 = x;
            } else if (x >= m3) {
                m3 = x;
            }
        }

        return max(n1 * n2 * m1, m1 * m2 * m3);
    }
};