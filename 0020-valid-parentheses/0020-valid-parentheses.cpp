class Solution {
public:
    bool isValid(string s) {
        // odd size
        if (s.size() % 2 != 0)
            return false;

        unordered_map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};
        vector<char> stack;

        int r = s.size() - 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push_back(s[i]); // push opening bracket
            else {
                if (stack.empty() || mp[s[i]] != stack.back())
                    return false;
                stack.pop_back(); // pop corresponding opening brackets
            }
        }
        return stack.empty();
    }
};