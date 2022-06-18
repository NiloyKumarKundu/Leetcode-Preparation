#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int posOne = s.find("AB");
	int posTwo = s.find("BA", posOne + 2);


	int pos1 = s.find("BA");
	int pos2 = s.find("AB", pos1 + 2);

	if ((posOne != -1 && posTwo != -1) || (pos1 != -1 && pos2 != -1)) {
		cout << "YES" << endl;
	} else
		cout << "NO" << endl;
	return 0;
}