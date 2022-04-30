class Solution {
public:
    void dfs(string s, string d, map<string, vector<pair<string, double>>>& mp, set<string> vis, double& ans, double temp) {
       if (vis.find(s) != vis.end())
           return;
        vis.insert(s);
        if (s == d) {
            ans = temp;
            return;
        }
        
        for (auto a : mp[s]) {
            dfs(a.first, d, mp, vis, ans, temp * a.second);
            
        }
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string, vector<pair<string, double>>> mp;
        for (int i = 0; i < e.size(); i++) {
            mp[e[i][0]].push_back({e[i][1], v[i]});
            mp[e[i][1]].push_back({e[i][0], 1.0 / v[i]});
        }
        
        vector<double> res;
        
        for (int i = 0; i < q.size(); i++) {
            string src = q[i][0];
            string dest = q[i][1];
            set<string> vis;
            double ans = -1;
            
            if (mp.find(src) != mp.end()) {
                dfs(src, dest, mp, vis, ans, 1.0);
            }
            res.push_back(ans);
        }
        return res;
    }
};

