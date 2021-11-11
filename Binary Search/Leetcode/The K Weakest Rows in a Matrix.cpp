class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int, int>> m;
        for (auto i = 0; i < mat.size(); ++i) {
            auto p = accumulate(begin(mat[i]), end(mat[i]), 0);
            m.insert({p, i});
        }
        vector<int> res;
        for (auto it = begin(m); k > 0; it++, k--) {
            res.push_back(it->second);
        }
        return res;
    }
};



// Another Solution
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> res;
        vector<int> ans;
        
        for (int i = 0; i < mat.size(); i++) {
            reverse(mat[i].begin(),mat[i].end());
            int x = lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin();

            res.push_back({mat[i].size() - x, i});
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < k; i++) {
            ans.push_back(res[i].second);
        }
        
        return ans;
    }
};




// Another Solution

class Solution {
public:
    int upper_bound_Rev(vector<int> arr) {
        int low = 0, high = arr.size() - 1;
        int target = 1;
        int ans = -1;
        
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] >= target) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (ans == -1) 
            return 0;
        return ans + 1;
    }
    
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> res;
        vector<int> ans;
        
        
        for (int i = 0; i < mat.size(); i++) {
            int y = upper_bound_Rev(mat[i]);
            
            cout << y << endl;

            res.push_back({y, i});
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < k; i++) {
            ans.push_back(res[i].second);
        }
        
        return ans;
    }
};