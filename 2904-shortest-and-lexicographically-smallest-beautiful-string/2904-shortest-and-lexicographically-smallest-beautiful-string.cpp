class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int i = 0;
        while (i < n && s[i] != '1')
            i++;

        int c = 0;
        for (int temp = i; temp < n; temp++) {
            if (s[temp] == '1')
                c++;
        }
        if (c < k)
            return "";

        int count = 0, j = i;

        while (k) {
            if (s[j] == '1')
                k--;
            j++;
            count++;
        }

        int minCount = count, idx = i;

        for (; j < n; j++) {
            count++;
            if (s[j] == '1') {
                do {
                    i++;
                    count--;
                } while (s[i] != '1');

                if (count < minCount ||
                    (count == minCount &&
                     s.compare(i, count, s, idx, minCount) < 0)) {
                    minCount = count;
                    idx = i;
                }
            }
        }

        return s.substr(idx, minCount);
    }
};