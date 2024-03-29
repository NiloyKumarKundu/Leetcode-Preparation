class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, maxi = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            sum += prices[i] - prices[i - 1];
            if (sum < 0) {
                sum = 0;
            } else {
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};