class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int w1[26], w2[26];
        memset(w1, 0, sizeof(w1));
        memset(w2, 0, sizeof(w2));
        
        for (int i = 0; i < word1.size(); i++) {
            w1[word1[i] - 'a']++;
        }
        
        for (int i = 0; i < word2.size(); i++) {
            w2[word2[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (abs(w1[i] - w2[i]) > 3) {
                return false;
            }
        }
        
        
        return true;
    }
};