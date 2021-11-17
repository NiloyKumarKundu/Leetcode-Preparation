// XOR of same element is equal to 0. !important

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n + 1 == 1) {
            return nums[0];
        } else if (nums[0] != nums[1]) {
            return nums[0];
        } else if (nums[n] != nums[n - 1]) {
            return nums[n];
        }
        
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            } else if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 && nums[mid] == nums[mid - 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};