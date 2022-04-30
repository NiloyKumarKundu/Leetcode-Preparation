#include <bits/stdc++.h>
#define Niloy
#define int int64_t
#define mx (int) 1e5 + 123
// constexpr int64_t INF = std::numeric_limits<int64_t>::max();
#define INF (int) 1e9 + 7
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


// Input Overloading

template <typename T> 
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}

/* ----------------------------------------------------------------------------------- */



void input() {
#ifdef Niloy
    read("input.txt");  
    write("output.txt");
#endif
}

/* ----------------------------------------------------------------------------------- */

// Negative cycle weight aslei Bellman Ford.


struct node {
	int u, v, wt;

    node(int first, int second, int weight) {
		u = first;
		v = second;
		wt = weight;
	}
};

vector<node> edges;
vi dist;
int n, m;

void bellmanFord(int src) {
    dist.resize(n, INF);
	dist[0] = 0;

    rep(i, 0, n) {
        for (auto it : edges) {
            if (dist[it.u] + it.wt < dist[it.v]) {
				dist[it.v] = dist[it.u] + it.wt;
			}
		}
	}
}

bool hasNegativeCycle() {
    for (auto it : edges) {
        if (dist[it.u] + it.wt < dist[it.v]) {
			return true;
		}
	}
	return false;
}

void solve() {
	cin >> n >> m;
	edges.clear();

	while (m--) {
		int x, y, wt;
		cin >> x >> y >> wt;
		edges.push_back(node(x, y, wt));
	}

	bellmanFord(0);

	if (hasNegativeCycle()) {
		cout << "possible\n";
	} else {
		cout << "not possible\n";
	}
}

int32_t main() {
    // input();
    fastInput;
    // solve();

    __test {
    	solve();
    }

    // showTime;
    return 0;
}
