#include <bits/stdc++.h>
using namespace std;

int main() {
	map<char, int> mp;
	string s;

    while (cin >> s) {
        if (s == ".") {
			break;
		}
		mp.clear();
		for (int i = 0; i < s.length(); i++) {
			mp[s[i]]++;
		}
		
		cout << mp['a'] << endl;
	}
}