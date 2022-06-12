#include <bits/stdc++.h>
using namespace std;
#define int int64_t


int32_t main() {
	int n;
    cin >> n;
	int res = 0;
    if (n >= 1000) {
		res += (n - 999);
	}
    if (n >= 1000000) {
		res += (n - 999999);
	}

    if (n >= 1000000000) {
		res += (n - 999999999);
	}

    if (n >= 1000000000000) {
		res += (n - 999999999999);
	}

    if (n >= 1000000000000000) {
		res += (n - 999999999999999);
	}
	cout << res << endl;
}