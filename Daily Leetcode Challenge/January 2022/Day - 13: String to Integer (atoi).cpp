class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        
        if (i > s.length()) {
            return 0;
        }
        
        int sign = 1;
        
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '+') ? +1 : -1;
            i++;
        }
        
        if (i > s.length()) {
            return 0;
        }
        
        
        for (; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++) {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            res *= 10;
            res += (s[i] - '0');
        }
        
        
        return res * sign;
    }
};