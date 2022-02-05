class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            set<int> st;
            for (auto num : nums) {
                st.insert(num & mask);
            }
            
            int tempMask = max | (1 << i);
            for (auto prefix : st) {
                if (st.find(tempMask ^ prefix) != st.end()) {
                    max = tempMask;
                    break;
                }
            }
        }
        return max;
    }
};