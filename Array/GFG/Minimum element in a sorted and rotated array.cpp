// Time Complixity: O(NlogN)

class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int l = 0, r = n - 1;
        
        while (l < r) {
            if (arr[l] <= arr[r]) {
                return arr[l];
            }
            int mid = l + (r - l) / 2;
            if (arr[mid] >= arr[l]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return arr[l];
    }
};