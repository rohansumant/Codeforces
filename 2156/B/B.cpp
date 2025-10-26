#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s; cin >> s;
    int nob = 0;
    if (find(s.begin(), s.end(), 'B') == s.end()) {
        nob = 1;
    }
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        int ans = nob ? x : 0;
        if (!nob) for (int j = 0; x; j = (j+1)%n) {
            char ch = s[j];
            if (ch == 'A') x--;
            else x /= 2;
            ans++;
        }
        cout << ans << endl;
    }
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

