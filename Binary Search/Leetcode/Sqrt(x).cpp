class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        long long low = 1, high = x / 2, res = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = mid * mid;
            if (count == x) {
                return mid;
            } else if (count < x) {
                low = mid + 1;
                res = mid;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};