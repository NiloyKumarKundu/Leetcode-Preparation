#include <bits/stdc++.h>
using namespace std;
#define read(x)	 freopen(x, "r", stdin);
#define write(x) freopen(x, "w", stdout);
#define ll		 long long
#define lli		 long long int
#define MAX		 100

bool isPrime(int n) {
	// Corner case
	if (n == 1)
		return false;

	// Check from 2 to n-1
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

	return true;
}

int main() {

	int ans[MAX];
	for (int i = 0; i < MAX; i++) {

		ans[i] = 0;
	}
	int cnt = 0;
	for (int i = 1; i <= MAX; i++) {
		cnt = 0;
		int temp = i;
		if (isPrime(temp)) {
			while (temp > 0) {
				int rem = temp % 10;

				if (rem == 0) {
					cnt = 1;
					break;
				}
				temp /= 10;
			}
            
			if (cnt == 0) {

				ans[i] += (ans[i - 1] + 1);
			} else {

				ans[i] = ans[i - 1];
			}

		} else {
			ans[i] = ans[i - 1];
		}
	}
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cout << ans[n] << endl;
	}

	return 0;
}
