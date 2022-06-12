#include <bits/stdc++.h>
using namespace std;


int main() {
	int a, b, w;
	cin >> a >> b >> w;
	w *= 1000;
	int mini = INT_MAX, maxi = 0;

	for (int i = 1; i <= 1000 * 1000; i++) {
        if ((a * i <= w) && (w <= b * i)) {
			mini = min(mini, i);
			maxi = max(mini, i);
		}
	}
    if (maxi == 0) {
		cout << "UNSATISFIABLE\n";
		return 0;
	}
	cout << mini << " " << maxi << endl;
}

