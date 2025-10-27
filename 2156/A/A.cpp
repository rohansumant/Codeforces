#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        int ans;
        if (x == 3 || x == 4) ans = 1;
        else {
            int diff;
            if (x&1) diff = x - 3;
            else diff = x - 4;
            ans = 1 + diff/2;
        }
        cout << ans << endl;
    }
    return 0;
}
