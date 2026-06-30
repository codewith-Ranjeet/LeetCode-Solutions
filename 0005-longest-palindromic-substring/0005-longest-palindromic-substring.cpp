class Solution {
public:
    bool isPalindrome(string& s, int st, int end) {
        while (st < end) {
            if (s[st] != s[end])
                return false;
            st++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {

                if (isPalindrome(s, i, j)) {

                    int len = j - i + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};