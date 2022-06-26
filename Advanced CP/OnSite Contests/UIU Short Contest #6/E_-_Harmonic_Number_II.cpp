#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int t;
	ll n;
	int cases = 0;
	cin >> t;

	while (t--) {
		cases++;
		ll half, sum = 0;
		cin >> n;

		half = (int) sqrt(n);

		for (int i = 1; i <= half; i++) {
			sum = sum + n / i;
		}
		
		sum = sum * 2;
		sum = sum - (half * half);
		cout << "Case " << cases << ": " << sum << endl;
	}
	return 0;
}