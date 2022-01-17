// Time Complexity: O(Len(pattern) * Len(s))
// Space Complexity: O(Len(pattern))

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> char_map;
        unordered_map<string, int> word_map;
        
        stringstream s(str);
        int n = pattern.length(), i = 0;
        
        for (string word; s >> word; i++) {
            char ch = pattern[i];
            if (i == n || char_map[ch] != word_map[word]) {
                return false;
            } else {
                char_map[ch] = word_map[word] = i + 1;
            }
        }

        return i == n;
    }
};