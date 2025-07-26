#include <bits/stdc++.h>
using namespace std;

int main() {
	bool good[26] = {};
	string good_string;	cin >> good_string;
	for (auto ch: good_string) {
		good[ch-'a'] = true;
	}

	string pattern, query;
	cin >> pattern;

	auto match = [&](char p, char q) -> bool {
		if (p == '*') return false;
		if (p == '?') return good[q-'a'];
		return p == q;
	};

	auto ok = [&](int pl, int pr, int ql, int qr) -> bool {
		while (pl <= pr && ql <= qr && match(pattern[pl], query[ql])) {
			// cout << pl << " " << pr << " " << ql << " " << qr << endl;
			pl++; ql++;
		}
		if (pl > pr && ql > qr) return true; // no star
		while (pr >= pl && qr >= ql && match(pattern[pr], query[qr])) {
			pr--; qr--;
		}
		// printf("%d %d %d %d\n",ql,qr,pl,pr);
		if (pl != pr || pattern[pl] != '*') return false;
		// if (pattern[pl] == '?' || pattern[pr] == '?') return false;
		// assert(pl == pr && pattern[pl] == '*');
		while (ql <= qr) {
			if (good[query[ql]-'a']) return false;
			ql++;
		}
		return true;
	};

	int pl = pattern.length();

	int n; cin >> n;
	while(n--) {
		string ans = "NO";
		cin >> query;
		int ql = query.length();
		if (ok(0, pl-1, 0, ql-1)) {
			ans = "YES";
		}
		cout << ans << endl;
	}
	return 0;
}

