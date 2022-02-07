// More Efficient

class Solution {
public:
    char findTheDifference(string s, string t) {
        char x = 0;
        for (char i : s)
            x ^= i;
        for (char i : t) 
            x ^= i;
        return x;
    }
};





class Solution {
public:
    char findTheDifference(string s, string t) {
        if (s == "" && t.length() == 1) 
            return t[0];
        
        char x;
        
        unordered_map<char, int> mp;
        
        for (int i = 0; i < t.length(); i++) {
            mp[t[i]]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]--;
        }
        
        for (auto i : mp) {
            if (i.second != 0) {
                x = i.first;
            }
        }
        
        return x;
    }
};