#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int k = n / 2;
	int a = k, b = k;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
            if (j == k) {
				cout << '$';
			} else if (j == a) {
				cout << '$';
			}
            else if (j == b) {
				cout << '$';
			} else {
				cout << '_';
			}
		}
		cout << endl;
		a--;
		b++;
	}
	for (int i = 0; i < n; i++) {
		cout << '$';
	}
	cout << endl;
	a++;
	b--;
	for (int i = k + 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
            if (j == k) {
				cout << '$';
			} else if (j == a) {
				cout << '$';
			}
            else if (j == b) {
				cout << '$';
			} else {
				cout << '_';
			}
		}
		cout << endl;
		a++;
		b--;
	}
}