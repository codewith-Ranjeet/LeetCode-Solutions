class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        unsigned int rev = 0, num = x;
        while (num != 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        if (rev == x)
            return true;
        return false;
    }
};