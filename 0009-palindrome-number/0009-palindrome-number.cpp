class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        string num = to_string(x);
        int n = num.size();

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (num[i] != num[j])
                return false;
        }
        return true;
    }
};