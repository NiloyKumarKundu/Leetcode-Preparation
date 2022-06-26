#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
	int count = 0;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
			s[i] = 'B';
			s[i + 1] = 'C';
			s[i + 2] = 'A';
			count++;

			int x = i;
			while (s[i - 1] == 'A' && i >= 0) {
				s[i - 1] = 'B';
                s[i] = 'C';
                s[i + 1] = 'A';
				count++;
				i--;
			}
			i = x;
		}
	}
	// cout << s << endl;
	cout << count << endl;
}