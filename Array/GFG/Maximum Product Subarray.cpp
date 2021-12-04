class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long ans = INT_MIN;
	    long long curMin = 1, curMax = 1;
	    
	    for (int i = 0; i < n; i++) {
	        if (arr[i] == 0) {
	            curMin = 1;
	            curMax = 1;
	            continue;
	        }
	        
	        long long temp = arr[i] * curMax;
	        curMax = max({(long long) arr[i], temp, arr[i] * curMin});
	        curMin = min({(long long) arr[i], arr[i] * curMin, temp});
	        
	        ans = max(ans, curMax);
	    }
	    return ans;
	}
};