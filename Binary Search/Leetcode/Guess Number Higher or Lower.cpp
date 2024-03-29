/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n, num = -1000;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            num = guess(mid);
            if (num == 0) {
                return mid;
            } else if (num == -1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return num;
    }
};