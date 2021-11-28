class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        long long ans = 0;
        map<int, long long> mp;
        mp[0] = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                sum += -1;
            } else {
                sum += 1;
            }
            
            if (mp.find(sum) != mp.end()) {
                ans += mp[sum];
                mp[sum]++;
            } else {
                mp[sum] = 1;
            }
        }
        
        return ans;
    }
};