// Time: O(N) Space: O(1) Issue: No overlapping


class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
        // Your code goes here
        int ans = 0, temp = 0, i;
        
        for (i = 0; i < n - 1; i++) {
            temp ^= arr[i];
            ans ^= (i + 1);
        }
        
        ans ^= (i + 1);
        return (temp ^ ans);
    }
};

// Time: O(N) Space: O(1) Issue: Overlapping


class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
        // Your code goes here
        int ans = 0, temp = 0, i;
		ans = (n * (n + 1)) / 2;

		for (i = 0; i < n - 1; i++) {
            temp += arr[i];
        }
        return ans - temp;
    }
};