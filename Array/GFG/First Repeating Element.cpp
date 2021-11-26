// Time Complixity: O(N) on avg
// Space Complixity: O(N)

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        int ans = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
            
        }
        
        for (int i = 0; i < n; i++) {
            if (mp[arr[i]] >= 2) {
                return i + 1;
            }
        }
        return -1;
    }
};

// Another Solve same time complixity

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        int mini = -1;
        set<int> s;
        for (int i = n - 1; i >= 0; i--) {
            if (s.find(arr[i]) != s.end()) {
                mini = i;
            } else {
                s.insert(arr[i]);
            }
        }
        
        if (mini != -1) {
            return mini + 1;
        }
        return mini;
    }
};