class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int boat = 0;

        for (int i = 0, e = n - 1; i <= e; e--) {
            if (people[i] + people[e] <= limit) {
                boat++;
                i++;
            } else {
                boat++;
            }
        }
        return boat;
    }
};