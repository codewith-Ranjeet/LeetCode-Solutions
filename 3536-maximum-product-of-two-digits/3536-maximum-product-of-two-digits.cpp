class Solution {
public:
    int maxProduct(int n) {
        int m1 = 0, m2 = 0;
        for (; n; n /= 10) {
            const int x = n % 10;
            if (x >= m1) {
                m2 = m1;
                m1 = x;
            } else if (x > m2) {
                m2 = x;
            }
        }
        return m1 * m2;
    }
};