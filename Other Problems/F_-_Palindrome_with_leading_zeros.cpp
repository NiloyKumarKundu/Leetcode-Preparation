#include <bits/stdc++.h>
using namespace std;


int main() {
	string str;
    cin >> str;
	string rstr = str;
	reverse(rstr.begin(), rstr.end());
    if (str == rstr) {
		cout << "Yes\n";
	} else {
		int count = 0, i;
		for (i = str.length() - 1; i >= 0; i--) {
			if (str[i] != '0') {
				break;
			}
		}

		string temp = str.substr(0, 0 + i + 1);

		string rtemp = temp;
		reverse(rtemp.begin(), rtemp.end());
		// cout << temp << " " << rtemp << endl;
		if (temp == rtemp) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}