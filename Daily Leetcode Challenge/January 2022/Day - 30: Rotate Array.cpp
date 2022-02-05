class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        if (nums.size() == 0 || k <= 0) {
            return;
        }
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            nums[(i + k) % n] = temp[i];
        }
        
    }
};