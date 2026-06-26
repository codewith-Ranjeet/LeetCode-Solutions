class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1, i = 0;

        // skip leading space
        while (i < n && s[i] == ' ')
            i++;

        // track sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long num = 0;

        // parse digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check
            if (num > (INT_MAX - digit) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};