class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i = 0, count = 0, m = 200;
        bool res = false;
        
        while (tickets[k] != 0) {
            int x = tickets[i % tickets.size()];
            if (x == 0) {
                i++;
                continue;
            }
            tickets[i % tickets.size()]--; 
            count++;
            i++;
        }
        count += tickets[k];
        
        return count;
    }
};