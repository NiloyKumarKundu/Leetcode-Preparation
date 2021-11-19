class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int left = 0, right = 0;
        int cur_sum = 0;
        cur_sum += arr[right];
        for (int i = 0; i < n; i++) {
            while (cur_sum > s) {
                cur_sum -= arr[left];
                left++;
            }
            if (cur_sum == s) {
                return {left + 1, right + 1};
            }
            
            if (cur_sum < s) {
                right++;
                cur_sum += arr[right];
            }
        }
        return {-1};
    }
};
