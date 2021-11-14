class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};



// Another Solution
class Solution {
public:
    bool findElement(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int num = 2 * arr[mid];
            if (num == target) {
                return true;
            } else if (target > num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
    
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int zero = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                zero++;
            } else {
                if (findElement(arr, arr[i])) {
                    return true;
                }
            }
        }
        return zero >= 2;
    }
};