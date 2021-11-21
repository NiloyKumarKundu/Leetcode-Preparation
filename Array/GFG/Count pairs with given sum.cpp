class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int value = k - arr[i];
            if (mp[value]) {
                ans += mp[value];
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};