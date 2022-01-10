// Time Complixity: O(log(N))

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int result = 0, factor = 1;
        while (n > 0) {
            result += factor * (n % 2 == 0 ? 1 : 0);
            factor *= 2;
            n /= 2;
        }
        
        return result;       
    }
};



// Another Solution
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        string str = "";
        int result = 1;
        int temp = n;
        
        while (temp > 0) {
            result = temp % 2;
            temp /= 2;
            str += to_string(result);
        }

        int res = (((1 << str.length()) - 1) ^ n);
        
        return res;
    }
};