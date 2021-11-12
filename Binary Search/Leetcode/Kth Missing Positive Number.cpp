// O(logN)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] > k) {
            return k;
        }
        
        int ans = 0;
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] - (mid + 1) < k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans + k + 1; // index based 1
    }
};



// O(N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        while (i < arr.size() && arr[i] - (i + 1) < k) {
            i++;
        }
        return i + k;
    }
};



// O(N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int pnt = k;
        for (int a : arr) {
            if (a <= pnt) {
                pnt++;
            } else {
                break;
            }
        }
        return pnt;
    }
};



//Another
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ind = 0, count = 0;
        for (int i = 1; i < 2001; i++) {
            if (ind < arr.size() && arr[ind] == i) {
                ind++;
                continue;
            }
            count++;
            if (count == k) {
                return i;
            }
            
        }
        return 0;
    }
};