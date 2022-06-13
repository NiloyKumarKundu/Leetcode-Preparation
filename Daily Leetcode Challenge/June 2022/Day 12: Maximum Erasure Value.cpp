class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            while (mp[nums[j]]) {
                sum -= nums[i];
                mp.erase(nums[i]);
                i++;
            }
            sum += nums[j];
            mp[nums[j]]++;
            ans = max(ans, sum);
        }
        return ans;
    }
};