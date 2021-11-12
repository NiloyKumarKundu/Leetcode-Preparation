





// Another

class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int i = 1; i < 1001; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] >= i) {
                    count++;
                }
            }
            if (count == i) {
                return i;
            }
        }
        return -1;
    }
};


// Another

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int freq[1001];
        memset(freq, 0, sizeof(freq));
        for (int j = 0; j < nums.size(); j++) {
            freq[nums[j]]++;
        }
        
        int total = nums.size();
        for (int i = 0; i < 1001; i++) {
            if (i == total) {
                return i;
            }
            total -= freq[i];
        }
        
        return -1;
    }
};
