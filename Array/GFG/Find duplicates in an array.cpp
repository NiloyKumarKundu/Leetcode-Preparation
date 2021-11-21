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