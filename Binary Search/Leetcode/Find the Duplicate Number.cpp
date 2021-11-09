// O(nlogn) with space O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            if (count > mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};



// O(n) with space O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int arr[nums.size()];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (arr[i] > 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};