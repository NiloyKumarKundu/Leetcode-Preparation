class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        int maxi = 0, mini = 0, res = 0;
        sort(arr, arr + n);
        res = arr[n - 1] - arr[0];
        
        for (int i = 1; i < n; i++) {
            if (arr[i] >= k) {
                maxi = max(arr[i - 1] + k, arr[n - 1] - k);
                mini = min(arr[i] - k, arr[0] + k);
                res = min(res, maxi - mini);
            }
        }
        return res;
    }
};