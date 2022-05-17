#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dj[] = {0, 1, 0, -1, -1, 1, 1, -1};

bool is_valid(int i, int j) {
    return i >= 1 && i <= 8 && j >= 1 && j <= 8;
}

int t, r, c, k, grid[10][10];
bool vis[10][10];

void bfs(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({i, j});

    while(!Q.empty()) {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        vis[i][j] = true;
        for(int d = 0; d < 8; d++) {
            int ii = i + di[d];
            int jj = j + dj[d];
            if(is_valid(ii, jj) && !vis[ii][jj]) {
                Q.push({ii, jj});
                grid[ii][jj] = grid[i][j] + 1;
                vis[ii][jj] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while(t > 0) {
        cin >> r >> c >> k;
        for(int i = 0; i <= 9; i++) {
            for(int j = 0; j <= 9; j++) {
                vis[i][j] = false;
                grid[i][j] = 0;
            }
        }
        bfs(r, c);
        int ans = 0;
        for(int i = 1; i <= 8; i++) {
            for(int j = 1; j <= 8; j++) {
                if(grid[i][j] <= k) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
        t--;
    }
    return 0;
}