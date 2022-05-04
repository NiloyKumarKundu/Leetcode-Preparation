// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> mp;
        
        for (auto i : nums) {
            int sub = k - i;
            if (mp[sub] > 0) {
                ans++;
                mp[sub]--;
            } else {
                mp[i]++;
            }
        }
        return ans;
    }
};



// Time Complexity: O(NLogN)
// Space Complexity: O(1)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int first = 0, last = n - 1;
        
        int ans = 0;
        while (first < last) {
            if (nums[first] + nums[last] == k) {
                ans++;
                last--;
                first++;
            } else if (nums[first] + nums[last] > k) {
                last--;
            } else if (nums[first] + nums[last] < k) {
                first++;
            }
        }
        return ans;
    }
};