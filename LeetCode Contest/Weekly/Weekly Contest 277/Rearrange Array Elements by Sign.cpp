class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }
        
        int posIndx = 0, negIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = pos[posIndx++];
            } else {
                nums[i] = neg[negIndex++];
            }
        }
        return nums;
    }
};