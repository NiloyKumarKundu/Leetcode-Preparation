// Its a very good problem and make clear idea for cracking interview.

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), indx1, indx2;
        
        for (indx1 = n - 2; indx1 >= 0; indx1--) {
            if (nums[indx1] < nums[indx1 + 1]) {
                break;
            }
        }
        
        if (indx1 < 0)
            return reverse(nums.begin(), nums.end());
        
        for (indx2 = n - 1; indx2 >= 0; indx2--) {
            if (nums[indx2] > nums[indx1]) {
                break;
            }
        }
        
        swap(nums[indx1], nums[indx2]);
        
        return reverse(nums.begin() + indx1 + 1, nums.end());
    }
};