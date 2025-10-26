#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    unordered_map<int, int> mp;
    int ix = 0;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        while (ix < n && a[ix] < 4*i) {
            mp[a[ix]]++;
            ix++;
        }
        int erasure_needed = ix;
        for (int j = 1; j < 4; j++) {
            erasure_needed -= mp.count(i*j) ? mp[i*j] : 0;
        }
        if (erasure_needed <= k) ans = max(ans, i);
    }
    cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while(t--) solve();
    return 0;
}
