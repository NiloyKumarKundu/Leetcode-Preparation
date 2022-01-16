// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int empty = 0, result = 0, idx1 = -1, idx2 = -1;
        
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                empty = 0;
                if (idx1 == -1) {
                    idx1 = i;
                }
                idx2 = i;
            } else {
                empty++;
                result = max(result, (empty + 1) / 2);
            }
        }
        result = max({result, idx1, n - 1 - idx2});
        
        return result;
    }
};