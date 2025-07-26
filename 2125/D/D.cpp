#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
//vector<ll> inv;
ll ALL_NEGATIVE = 1LL;
vector<ll> dp;

vector<ll> gen_inv(int n) {
	vector<ll> inv(n+1);
	/*
		 aq + r = p
		 inv(a) = -q/r
		 = p - p/a % MOD * inv(p%a)
	*/
	inv[1] = 1;
	for (ll i = 2; i <= n; i++) {
		inv[i] = (MOD - MOD/i * inv[MOD%i] % MOD) % MOD;
	}
	return inv;
}

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll half = pow(a,b/2);
	half = half * half % MOD;
	return (b&1 ? half*a : half) % MOD;
}

ll inv(ll x) {
	return pow(x, MOD-2);
}


ll mul(initializer_list<ll> args) {
	ll ans = 1;
	for (ll i: args) {
		ans = ans * i % MOD;
	}
	return ans;
}

int solve(int x, const vector<vector<array<int,3>>> &nl) {
	// assert(x >= 0);
	if (x == 0) return ALL_NEGATIVE;
	if (nl[x].empty()) return 0;
	//ll all = 1; // all inverse (no segment is 'picked')
	//for (auto arr: nl[x]) {
		//ll l = arr[0], p = arr[1], q = arr[2];
		//all = mul({all, (q-p), inv[q]});
	//}
	////cout << "all: " << all << endl;
	if (dp[x] != -1) return dp[x];
	ll ans = 0;
	for (auto arr: nl[x]) {
		ll l = arr[0], p = arr[1], q = arr[2];
		ans = (ans + mul({p, inv(q), q, inv(q-p), solve(l-1, nl)})) % MOD;
	}
	dp[x] = ans;
	return ans;
}

int main() {
	// inv = gen_inv(2e5+10);
	//for (ll i = 1; i < inv.size(); i++) {
		//assert(i * inv[i] % MOD == 1);
	//}
	int n,m;
	cin >> n >> m;
	dp = vector<ll> (m+1, -1);
	vector<vector<array<int,3>>> nl(m+1); // number line until 'm'
  while (n--) {
		int l, r, p, q;
		cin >> l >> r >> p >> q;
		ALL_NEGATIVE = mul({ALL_NEGATIVE, q-p, inv(q)});
		nl[r].push_back({l,p,q});
	}
	cout << solve(m, nl) << endl;
	return 0;
}
