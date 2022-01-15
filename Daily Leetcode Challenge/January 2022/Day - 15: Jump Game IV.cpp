class Solution {
public:
    int minJumps(vector<int>& arr) {
        int jump = 0;
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        
        vis[0] = 1;
        bool done = 0;
        
        while (!q.empty()) {
            int s = q.size();
            while(s--) {
                int i = q.front();
                q.pop();
                if (i == n - 1) {
                    done = true;
                    break;
                }
                
                if (i + 1 < n && vis[i + 1] == 0) {
                    q.push(i + 1);
                    vis[i + 1] = 1;
                }
                if (i - 1 >= 0 && vis[i - 1] == 0) {
                    q.push(i - 1);
                    vis[i - 1] = 1;
                }
                
                if (mp.count(arr[i])) {
                    for (auto idx : mp[arr[i]]) {
                        if (vis[idx] == 0) {
                            q.push(idx);
                            vis[idx] = 1;
                        }
                    }
                    mp.erase(arr[i]);
                }
            }
            if (done) {
                break;
            } else {
                jump++;
            }
        }
        return jump;
    }
};
















