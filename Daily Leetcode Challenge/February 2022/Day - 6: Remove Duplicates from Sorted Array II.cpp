// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) 
            return nums.size();
        
        int indx = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[indx - 2]) {
                nums[indx++] = nums[i];
            }
        }
        return indx;
    }
};