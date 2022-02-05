class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        while (num > 0) {
            v.push_back(num % 10);
            num /= 10;
        }
        sort(v.begin(), v.end());
    
        
        int a = 0, b = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i & 1) {
                a *= 10;
                a += v[i];
            } else {
                b *= 10;
                b += v[i];
            }
        }
        return a + b;
    }
};