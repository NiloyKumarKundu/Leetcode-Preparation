#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll int calculate(int height[], int cost[], int n, int x) {
	ll int res = 0;
	for (int i = 0; i < n; i++) {
		res += (abs(height[i] - x) * cost[i]);
	}
	return (res);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int height[n], cost[n];

		int mini = INT_MAX, maxi = 0;

		for (int i = 0; i < n; i++) {
			cin >> height[i];
			if (height[i] < mini)
				mini = height[i];

			if (height[i] > maxi)
				maxi = height[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> cost[i];
		}
        
		int start = mini;
		int end = maxi;
		ll int answer = 0;

		while (start <= end) {
			int mid = start + (end - start) / 2;
			ll int tempAns = calculate(height, cost, n, mid);
			ll int tempLeft = calculate(height, cost, n, mid - 1);
			ll int tempRight = calculate(height, cost, n, mid + 1);

			if (tempAns < tempLeft && tempAns < tempRight) {
				answer = tempAns;
				break;
			} else if (tempAns > tempLeft && tempAns < tempRight) {
				end = mid - 1;
			} else if (tempAns < tempLeft && tempAns > tempRight) {
				start = mid + 1;
			}
		}

		cout << answer << endl;
	}
}