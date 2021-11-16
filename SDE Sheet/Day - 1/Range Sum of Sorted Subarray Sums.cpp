// Brute Force

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long int sum = 0;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        sum = 0;
        
        for (int i = left - 1; i < right; i++) {
            int x = v[i];
            sum = ((sum % 1000000007) + (x % 1000000007)) % 1000000007;
        }
        return sum;
    }
};