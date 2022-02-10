class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (binary_search(nums.begin() + i + 1, nums.end(), nums[i] + k)) {
                st.insert({nums[i], nums[i] + k});
            }
        }
        return st.size();
    }
};