// Without using long long

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = num / mid, remain = num % mid;
            if (res == mid && remain == 0) {
                return true;
            } else if (res > mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};



// Another

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = mid * mid;
            if (count == num) {
                return true;
            } else if (count > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};