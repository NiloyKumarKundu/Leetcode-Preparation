class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto i : nums) {
            mp[i]++;
        }
            
        for (int i = 0; i < nums.size(); i++) {
            int x = mp[nums[i]];
            if (x == 1) {
                if (mp.find(nums[i] + 1) != mp.end() || mp.find(nums[i] - 1) != mp.end()) {
                    continue;
                }
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};