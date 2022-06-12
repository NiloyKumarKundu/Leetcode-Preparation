#include <bits/stdc++.h>
using namespace std;

#define int int64_t


int countDigit(int n) {
	int count = 0;
    while (n > 0) {
		n /= 10;
		count++;
	}
	return count;
}

bool sameString(string x, string y) {
	return x == y;
}

int32_t main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int count = countDigit(i);
        if (count % 2 == 0) {
            string x = to_string(i);
            string a = "", b = "";
            int j = 0;
            for (j = 0; j < x.size() / 2; j++) {
                a += x[j];
            }


            for (; j < x.size(); j++) {
                b += x[j];
            }

            if (sameString(a, b)) {
                ans++;
            }
        }
	}

	cout << ans << endl;
}
