class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        int center = arr[(n - 1) / 2];

        sort(arr.begin(), arr.end(), [center](int a, int b) {
            int diff_a = std::abs(a - center);
            int diff_b = std::abs(b - center);

            if (diff_a == diff_b) {
                return a > b;
            }
            return diff_a > diff_b;
        });

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};