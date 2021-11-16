// Brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    if (nums[i] + nums[j] == target) {
                        return {i, j};
                    }
                }
            }
        }
        return {0, 1};
    }
};

// Optimal
// Time complixity: O(N)
// Space Complixity: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int num_to_find = target - nums[i];
            if (mp.find(num_to_find) != mp.end()) {
                v.push_back(mp[num_to_find]);
                v.push_back(i);
            }
            mp[nums[i]] = i;
        }
        return v;
    }
};