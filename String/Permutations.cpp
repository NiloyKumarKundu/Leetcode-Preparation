// Time Complexity: O(N * N!)
// Space Complexity: O(N) + O(N)

class Solution {
public:
    void calPermutation(vector<int> &nums, vector<vector<int>> &ans, int l, int r) {
        if (l == r) {
            ans.push_back(nums);
        } else {
            for (int i = l; i <= r; i++) {
                swap(nums[l], nums[i]);
                calPermutation(nums, ans, l + 1, r);
                swap(nums[l], nums[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int l = 0, r = nums.size() - 1;
        calPermutation(nums, ans, l, r);
        return ans;
    }
};