class Solution {
    bool palindrome(string s) {
        int i = 0, j = s.length() - 1;
        
        while (i <= j) {
            if (s[i] != s[j]) 
                return false;
            i++;
            j--;
        }
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        
        if (palindrome(s))
            return true;
        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return palindrome(s.substr(i, j - i)) || palindrome(s.substr(i + 1, j - i));
            }
        }
        
        return false;
    }
};