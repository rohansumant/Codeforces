#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// primes: 2, 3, 5, 7
ll get(ll x) {
	ll ans = 0LL;
	for (ll i: {2, 3, 5, 7}) {
		ans += x/i;
	}
	for (ll i: {6, 15, 35, 14, 10, 21}) {
		ans -= x/i;
	}
	for (ll i: {30, 105, 70, 42}) {
		ans += x/i;
	}
	for (ll i: {210}) {
		ans -= x/i;
	}
	return ans;
}

int main() {
	int t; cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		ll ans = get(b) - get(a-1);
		cout << b-a+1LL-ans << endl;
	}
	return 0;
}
