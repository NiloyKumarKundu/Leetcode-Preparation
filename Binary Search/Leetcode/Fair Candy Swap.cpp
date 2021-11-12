// O(NlogN)
class Solution {
public:
    int binarysearch(vector<int>& b, int delta) {
        int low = 0, high = b.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (b[mid] == delta) {
                return mid;
            } else if (delta > b[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    
    
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sa = accumulate(a.begin(), a.end(), 0);
        int sb = accumulate(b.begin(), b.end(), 0);
        int delta = (sb - sa) / 2;
        sort(b.begin(), b.end());
        
        for (int i = 0; i < a.size(); i++) {
            int loc = binarysearch(b, a[i] + delta);
            if (loc != -1) {
                return {a[i], a[i] + delta};
            }
        }
        return {0, 0};
    }
};





// Another Solve O(N)

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int aSum = 0;
        int bSum = 0;
        int delta;
        vector<int> ans;
        set<int> s1;
        
        
        for (int i = 0; i < b.size(); i++) {
            bSum += b[i];
            s1.insert(b[i]);
        }
        
        for (int i = 0; i < a.size(); i++) {
            aSum += a[i];
        }
        
        delta = (bSum - aSum) / 2;
        
        for (int k = 0; k < a.size(); k++) {
            auto it = s1.find(a[k] + delta);
            if (it != s1.end()) {
                ans.push_back(a[k]);
                ans.push_back(a[k] + delta);
                return ans;
            } 
        }
        return ans;
    }
};





// Another Solve O(N^2)

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bobSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int n = aliceSizes.size(), m = bobSizes.size();
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int sub = aliceSizes[i] - bobSizes[j];
                if (aliceSum - sub == bobSum + sub) {
                    return {aliceSizes[i], bobSizes[j]};
                }
                
            }
        }
        
        return aliceSizes;
    }
};