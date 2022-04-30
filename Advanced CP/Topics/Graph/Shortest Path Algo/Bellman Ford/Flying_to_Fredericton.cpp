#include <bits/stdc++.h>
#define Niloy
#define int int64_t
#define mx (int) 1e5 + 123
// constexpr int64_t INF = std::numeric_limits<int64_t>::max();
// #define INF (int) 1e9 + 7
const int INF = 1<<29;
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
 
#define Cases  cout << "Scenario #" << ++Case << endl;
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

string city[mx];
map<string, int> cityIndex;
vector<node> edges;
int n, m;


int bellmanFord(int stopCount) {
	vi dist(n, INF);
	dist[0] = 0;

	REP(i, 0, stopCount) {
        int temp[n];

        rep(i, 0, n) {
			temp[i] = dist[i];
		}

        for (auto it : edges) {
			temp[it.v] = min(temp[it.v], dist[it.u] + it.wt);
		}

        for(int i = 0; i < n; i ++) {
            dist[i] = temp[i];
        }
	}
	return dist[n - 1];
}

int setIndex(string cityName) {
	int currentIndex = cityIndex.size();
	cityIndex[cityName] = currentIndex;
	return currentIndex;
}

int getIndex(string cityName) {
	return cityIndex[cityName];
}

void solve() {
	cityIndex.clear();
	edges.clear();
	city->clear();
	cin >> n;

	rep(i, 0, n) {
		cin >> city[i];
		setIndex(city[i]);
	}

	cin >> m;
    rep(i, 0, m) {
		string x, y;
		int wt;
		cin >> x;
		cin >> y;
		cin >> wt;
		int first = getIndex(x);
		int second = getIndex(y);
		edges.push_back(node(first, second, wt));
	}

    // for (auto i : edges) {
	// 	cout << i.u << " " << i.v << " " << i.wt << endl;
	// }
	// cout << endl;

	int q, stopCount;
	cin >> q;
    while (q--) {
		cin >> stopCount;
        // dbg(stopCount);
		int minDistance = bellmanFord(stopCount);

        // rep(i, 0, n) {
		// 	cout << dist[i] << " ";
		// }
		// cout << endl;

		if (minDistance != INF) {
            cout << "Total cost of flight(s) is $" << minDistance << endl;
        } else {
            cout << "No satisfactory flights" << endl;
        }
	}
}

int32_t main() {
    // input();
    fastInput;
    // solve();
	__test {
		Cases;
		solve();
        if (tt) {
		    cout << endl;
        }
	}

	// showTime;
    return 0;
}
