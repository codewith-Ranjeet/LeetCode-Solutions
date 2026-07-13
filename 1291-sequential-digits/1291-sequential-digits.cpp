class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> r;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; i + j <= 10; j++) {
                int v = 0;
                for (int k = 0; k < i; k++) {
                    v = v * 10 + (j + k);
                }
                if (v > high) {
                    return r;
                }
                if (v >= low) {
                    r.push_back(v);
                }
            }
        }
        return r;
        
    }
};