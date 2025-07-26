#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a%b);
}

int main() {
	int t; cin >> t;
	while(t--) {
		ll a, b, k;
		cin >> a >> b >> k;
		int ans = 2;
		if (a == b) ans = 1;
		ll g = gcd(a,b);
		//assert(a%g == 0);
		//assert(b%g == 0);
		//cout << "G: " << g << endl;
		if (max(a/g, b/g) <= k) ans = 1;
		cout << ans << endl;
	}
	return 0;
}

