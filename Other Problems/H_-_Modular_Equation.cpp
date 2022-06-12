#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
    cin >> t;
    while (t--) {
		int n, m;
		cin >> n >> m;
		int count = 0;

		for (int i = 1; i <= n; i++) {
			int x = i;
			int y = n;
			// cout << x << " " << y << endl;
			int a = ((m % x) % y);
			int b = ((m % y) % x);
            if (a == b) {
				count++;
			}
		}
		cout << count << endl;
	}
}
