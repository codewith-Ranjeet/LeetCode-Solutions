class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        if (n == 1)
            return 1;

        sort(people.begin(), people.end());
        int boat = 0;

        int e = n - 1;
        for (; people[e] == limit; e--)
            boat++;

        for (int i = 0; i <= e;) {
            if (people[i] + people[e] <= limit) {
                boat++;
                i++;
                e--;
            } else {
                boat++;
                e--;
            }
        }
        return boat;
    }
};