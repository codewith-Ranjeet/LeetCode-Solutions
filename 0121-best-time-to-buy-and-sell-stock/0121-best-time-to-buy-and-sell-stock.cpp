
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int max_Profit = 0;

        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            max_Profit = max(max_Profit, prices[i] - minPrice);
        }
        return max_Profit;
    }
};

