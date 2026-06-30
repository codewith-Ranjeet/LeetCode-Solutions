class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> z(numRows, "");
        int n = s.size();
        for (int i = 0; i < n;) {
            for (int j = 0; j < numRows && i < n; j++) {
                z[j] += s[i++];
            }

            for (int j = numRows - 2; j > 0 && i < n; j--)
                z[j] += s[i++];
        }

        string finalString = "";
        for (int i = 0; i < numRows; i++)
            finalString += z[i];

        return finalString;
    }
};