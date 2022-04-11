class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> p;
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        for (auto i : mp) {
            p.push({i.second, i.first});
        }
    
        while (k--) {
            ans.push_back(p.top().second);
            p.pop();
        }
        
        return ans;
    }
};