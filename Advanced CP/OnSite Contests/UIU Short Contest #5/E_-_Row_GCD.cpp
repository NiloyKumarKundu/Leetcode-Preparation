#include <bits/stdc++.h>
using namespace std;

long long gcd(long long n, long long m) { return m ? gcd(m, n % m) : n; }

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> v1, v2;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		v1.push_back(x);
	}

	for (int i = 0; i < m; i++) {
		long long x;
		cin >> x;
		v2.push_back(x);
	}

	long long x = 0;
	for (int i = 1; i < n; i++) {
		x = gcd(x, abs(v1[i] - v1[i - 1]));
	}


	for (int i = 0; i < m; i++) {
		cout << gcd(x, v2[i] + v1[0]) << " ";
	}
	cout << endl;
}