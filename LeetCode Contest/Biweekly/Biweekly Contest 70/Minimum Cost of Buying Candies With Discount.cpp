class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int cnt = 0, sum = 0;
        for (int i = cost.size() - 1; i >= 0; i--) {
            if (cnt % 2 == 0 && cnt != 0) {
                cnt = 0;
                continue;
            } else {
                sum += cost[i];
            }
            cnt++;
        }
        return sum;
    }
};