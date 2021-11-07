/*
	Travarse from top right corner and this will be our mid.
	Suppose, n*m matrix,
	then, i = 0, j = m - 1;

    if (mid > target) {
        then the whole column will be reduce. Because, the column is sorted. xD
        then j-- occur.
    } else {
        here the row will be reduced. Because, in the left side, the value are lower than the mid.
        so,
        i++ will be apear here.
    }

    worst case complixity: O(n + m) 

*/



#include <bits/stdc++.h>
#define Niloy
#define int int64_t
#define mx (int) 1e5 + 123
#define MOD (int) 1e9 + 7
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define llu unsigned long long
using namespace std;
/* ----------------------------------------------------------------------------------- */

// Input/Output
#define fastInput ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define square(a) (a * a)
#define mem(a, b) memset(a, b, sizeof(a))

// Fractional Number
#define fraction()        cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed, ios::floatfield);

// Direction Array
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

// File I/O
#define read(x)	 freopen(x, "r", stdin);
#define write(x) freopen(x, "w", stdout);
 
// Loops
#define rep(i, a, n) for (int i = a; i < n; i++)
#define REP(i, a, n) for (int i = a; i <= n; i++)
#define rev(i, n, a) for (int i = n - 1; i >= a; i--)
#define REV(i, n, a) for (int i = n; i >= a; i--)
 
/* ----------------------------------------------------------------------------------- */
 
#define Cases  cout << "Case " << ++Case << ": ";
#define __test int tt; int Case=0; cin >> tt; while(tt--)
#define showTime cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
 
#define dbgA2(A, n, m) {cout<<"--> "<<#A<<" = \n";rep(i, 0, n){rep(j, 0, m){cout<<A[i][j]<<"";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n) {cout<<" --> "<<#A<<" = (";rep(i, 0, n)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...) {string sss(#args);sss+=',';cout<<" --> ";debugger::call(all(sss), args);cout<<"\n";}
 
/* ----------------------------------------------------------------------------------- */
 
int gcd(int n, int m) { return m ? gcd(m, n % m) : n; }
int lcm(int n, int m) { return n / gcd(n, m) * m; }
 
struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it)
            if(*it!=' ')
                b+=*it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};

/* ----------------------------------------------------------------------------------- */
void input() {
#ifdef Niloy
    read("input.txt");  
    write("output.txt");
#endif
}

/* ----------------------------------------------------------------------------------- */


pair<int, int> BSon2D(vector<vector<int>> arr, int n, int m, int target) {
	int i = 0, j = m - 1;
	pair<int, int> ans;
	while (i >= 0 && i < n && j >= 0 && j < m) {
		if (arr[i][j] == target) {
			ans.first = i;
			ans.second = j;
			return ans;
		} else if (arr[i][j] > target) {
			j--;
		} else {
			i++;
		}
	}
	return {-1, -1};
}

void solve() {
    int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	rep(i, 0, n) {
		rep(j, 0, m) {
			cin >> arr[i][j];
		}
	}

	int target;
	cin >> target;
	pair<int, int> ans = BSon2D(arr, n, m, target);

	cout << ans.first << " " << ans.second << endl;
}

int32_t main() {
    // input();
    fastInput;
    solve();

    // __test {
    // 	solve();
    // }

    // showTime;
    return 0;
}


/*
Test Case:

4 4
10 20 30 40
15 25 35 45
27 29 37 45
32 33 39 50
*/ 