// Short Code

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() < 2) {
            return true;
        }
        if (isupper(word[0]) && isupper(word[1])) {
            for (int i = 2; i < word.length(); i++) {
                if (islower(word[i])) {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < word.length(); i++) {
                if (isupper(word[i])) {
                    return false;
                }
            }   
        }
        return true;
    }
};



// My try
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all = true, small = true;
        
        if (word.size() == 1) {
            return true;
        }
        
        for (int i = 0; i < word.length(); i++) {
            if (!(word[i] >= 'A' && word[i] <= 'Z')) {
                all = false;
                break;
            } 
        }
        if (all) {
            return true;
        }
        
        for (int i = 0; i < word.length(); i++) {
            if (!(word[i] >= 'a' && word[i] <= 'z')) {
                small = false;
                break;
            }
        }
        
        if (small) {
            return true;
        }
        
        if (word[0] >= 'A' && word[0] <= 'Z') {
            small = true;
            for (int i = 1; i < word.length(); i++) {
                if (!(word[i] >= 'a' && word[i] <= 'z')) {
                    small = false;
                    break;
                }
            }
            if (small) {
                return true;
            }
        }
        
        return false;
    }
};