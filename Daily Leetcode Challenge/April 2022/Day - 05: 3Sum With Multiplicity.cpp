// Brute Force 

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1000000007;
        int result = 0;
        
        for (int i = 0; i < arr.size() - 1; i++) {
            int count[101];
            memset(count, 0, sizeof(count));
            for (int j = i + 1; j < arr.size(); j++) {
                int k = target - arr[i] - arr[j];
                if (k >= 0 && k <= 100 && count[k] > 0) {
                    result += count[k];
                    result = result % mod;
                } 
                count[arr[j]]++;
            }
        }
        return result;
    }
};





// Optimised

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1000000007;
        long long int res = 0;
        long long int count[101];
        memset(count, 0, sizeof(count));
        
        for (int i : arr)
            count[i]++;
        
        for (int i = 0; i <= 100; i++) {
            for (int j = i; j <= 100; j++) {
                int k = target - i - j;
                if (k < 0 || k > 100)
                    continue;
                
                if (i == j && j == k) {
                    res += ((count[i] * (count[i] - 1) * (count[i] - 2)) / 6);
                } else if (i == j && j != k) {
                    res += ((count[i] * (count[i] - 1)) / 2) * count[k];
                } else if (i < j && j < k) {
                    res += (count[i] * count[j] * count[k]);
                }
            }
        }
        return (res % mod);
    }
};