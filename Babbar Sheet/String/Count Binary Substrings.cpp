// Optimised Approach
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int countBinarySubstrings(string s) {
        int current_sum = 1, previous_sum = 0, ans = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i - 1] != s[i]) {
                ans += min(current_sum, previous_sum);
                previous_sum = current_sum;
                current_sum = 1;    
            } else {
                current_sum++;
            }
        }
        ans += min(current_sum, previous_sum);
        
        return ans;
    }
};


// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> v(s.size());
        int indx = 0;
        v[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i - 1] != s[i]) {
                indx++;
                v[indx]  = 1;
            } else {
                v[indx]++;
            }
        }
        int count = 0;
        for (int i = 1; i <= indx; i++) {
            count += min(v[i - 1], v[i]);
        }
        return count;
    }
};