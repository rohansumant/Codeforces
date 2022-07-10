#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string a,b;
  cin >> a >> b;
  map<char,set<int>> mp;

  auto check = [&mp,&a](int ix, char got, char need, char skip) {
    int skip_ix = 2e5, need_ix = 2e5;
    auto skip_ptr = mp[skip].upper_bound(ix);
    if (skip_ptr != mp[skip].end()) {
      skip_ix = *skip_ptr;
    }
    auto need_ptr = mp[need].upper_bound(ix);
    if (need_ptr != mp[need].end()) {
      need_ix = *need_ptr;
    }
    if (need_ix == 2e5 || skip_ix < need_ix) return;
    // swap contents of ix and need_ix
    swap(a[ix],a[need_ix]);
    mp[got].erase(ix);
    mp[got].insert(need_ix);
    mp[need].erase(need_ix);
    mp[need].insert(ix);
  };


  for(int i=0;i<n;i++) {
    mp[a[i]].insert(i);
  }
  for(int i=0;i<n;i++) {
    bool ok = false;
    if (a[i] == b[i]) {
      ok = true;
    }
    else if (a[i] == b[i]-1) {
      check(i,a[i],b[i],(a[i] == 'a' ? 'c':'a'));
      ok = a[i] == b[i];
    }
    if (!ok) {
      cout << "NO\n";
      //cout << a << endl;
      return;
    }
    mp[a[i]].erase(i);
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
}
