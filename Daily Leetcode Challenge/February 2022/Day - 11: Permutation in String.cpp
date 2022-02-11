// Time Complexity: O(alphabet_size * length(s2))

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26, 0);
        vector<int> s2hash(26, 0);
        
        int s1len = s1.length();
        int s2len = s2.length();
        
        if (s1len > s2len)
            return false;
        
        int left = 0, right = 0;
        
        while (right < s1len) {
            s1hash[s1[right] - 'a']++;
            s2hash[s2[right] - 'a']++;
            right++;
        }
        right--;
        
        while (right < s2len) {
            if (s1hash == s2hash)
                return true;
            
            right++;
            if (right != s2len)
                s2hash[s2[right] - 'a']++;
            s2hash[s2[left] - 'a']--;
            left++;
        }
        return false;
    }
};