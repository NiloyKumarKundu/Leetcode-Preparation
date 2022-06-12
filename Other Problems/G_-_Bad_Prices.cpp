#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
    cin >> t;
    while (t--) {
        int n, count = 0;
        cin >> n;
        vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int temp = arr[n - 1];
		for (int i = arr.size() - 1; i >= 0; i--) {
			if (temp < arr[i]) {
				count++;
			} else {
				temp = arr[i];
			}
		}
		cout << count << endl;
	}
}