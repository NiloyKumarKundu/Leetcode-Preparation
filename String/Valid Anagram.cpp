// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int arr[26] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (arr[t[i] - 'a'] == 0) {
                return false;
            }
            arr[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (arr[i] < 0) {
                return false;
            }
        }
        
        return true;
    }
};


// Code Variations
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int arr[26] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (arr[i]) {
                return false;
            }
        }
        
        return true;
    }
};


// Code Variations
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> mp;
        
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for (auto i : mp) {
            if (i.second) {
                return false;
            }
        }
        
        return true;
    }
};


// Another Solution
// Time Complexity: O(N * log(N))
// Space Complexity: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {
            return true;
        }
        return false;
    }
};


// Code Variations
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};

