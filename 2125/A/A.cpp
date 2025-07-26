#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		sort(s.begin(), s.end(), [](char x, char y) {
				return x > y;
				});
		cout << s << endl;
	}
	return 0;
}
