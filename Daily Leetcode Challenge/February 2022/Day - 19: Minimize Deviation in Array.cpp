// Time Complexity: O(NlogNlogM); where M is the max value of the array.
// Space Complexity: O(N)

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for (auto& num : nums) {
            if (num & 1) {
                num += num;     // if odd, then multiply by 2;
            }
        }
        
        set<int, greater<int>> s(nums.begin(), nums.end());
        int ans = *s.begin() - *s.rbegin();
        
        while (*s.begin() % 2 == 0) {
            int x = *s.begin();
            s.erase(s.begin());
            s.insert(x / 2);
            ans = min(ans, (*s.begin() - *s.rbegin()));
        }
        return ans;
    }
};