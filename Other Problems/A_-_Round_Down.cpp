#include <bits/stdc++.h>
using namespace std;


int main() {
	string str, ans = "";
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
        if (ans == "" && str[i] == '0') {
            continue;
        }
        if (str[i] == '.') {
			break;
		}
		ans += str[i];
	}
    if (ans == "") {
		cout << "0\n";
		return 0;
	}
	cout << ans << endl;
}