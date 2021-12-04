class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int ans = arr[0];
	    int curMin = arr[0], curMax = arr[0];
	    
	    for (int i = 1; i < arr.size(); i++) {
	        int temp = arr[i] * curMax;
	        curMax = max({arr[i], temp, arr[i] * curMin});
	        curMin = min({arr[i], arr[i] * curMin, temp});
	        ans = max(ans, curMax);
	    }
	    return ans;
    }
};