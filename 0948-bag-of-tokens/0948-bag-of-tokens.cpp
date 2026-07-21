class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(tokens.begin(), tokens.end());
        if (n == 0 || tokens[0] > power)
            return 0;

        int score = 0;
        int i = 0, e = n - 1;

        for (; i < e;) {
            if (tokens[i] > power) {
                if(!score) break;
                score--;
                power += tokens[e--];
            } else {
                power -= tokens[i++];
                score++;
            }
        }

        if (i == e && tokens[i] <= power)
            return ++score;
            
        return score;
    }
};