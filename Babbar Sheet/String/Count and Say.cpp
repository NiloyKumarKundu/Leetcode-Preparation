class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        if (n == 2) {
            return "11";
        }
        
        string a = "11";
        int count = 1;
        for (int i = 3; i <= n; i++) {
            string t = "";
            count = 1;
            a += "$";
            for (int j = 1; j < a.length(); j++) {
                if (a[j - 1] == a[j]) {
                    count++;
                } else {
                    t += to_string(count) + a[j - 1];
                    count = 1;
                }
            }
            a = t;
        }
        return a;
    }
};