// Optimising the space somplixity
// Time Cox: O(N) Space Cox: O(1)

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> v;
        
        for (int i = 0; i < n; i++) {
            arr[arr[i] % n] += n;
        }
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] / n > 1) {
                v.push_back(i);
                flag = true;
            }
        }
        
        if (!flag) {
            v.push_back(-1);
        }
        return v;
    }
};

// Time Cox: O(N) Space Cox: O(N)

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        int freq[n];
        memset(freq, 0, sizeof(freq));
        
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        vector<int> v;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (freq[i] > 1) {
                flag = true;
                v.push_back(i);
            }
        }
        if (!flag) {
            v.push_back(-1);
        }
        return v;
    }
};