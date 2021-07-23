#include <bits/stdc++.h>
using namespace std;

/*
 * 2 1 2
 *
 * 3
 * 2 -> 1,3
 *
 */

void solve() {
  int n; cin >> n;
  vector<vector<int>> a(n+1);
  vector<int> org(n+1);
  for(int i=1;i<=n;i++) {
    int x; cin >> x;
    // i wants to give a gift to x
    org[i] = x;
    a[x].push_back(i);
  }
  unordered_set<int> loners;
  for(int i=1;i<=n;i++) if(a[i].empty()) {
    loners.insert(i);
  }
  vector<int> ans(n+1);
  int ix = 1;
  for(auto i: loners) {
    for(;ix <= n && a[ix].size() <= 1; ix++);
    if(a[ix].back() == i) {
      swap(a[ix][0],a[ix].back());
      assert(a[ix].back() != i);
    }
    int change_ix = a[ix].back();
    a[ix].pop_back();
    ans[change_ix] = i;
    //printf("%d %d\n",change_ix,i);
  }

  for(int i=1;i<=n;i++) {
    //printf("%d %d\n",ans[i],a[i].size());
    /*
    if(!ans[i]) {
      if(loners.count(i)) {
        ans[i] = org[i];
      } else {
        assert(a[i].size() == 1);
        ans[i] = a[i][0];
        assert(ans[i] != i);
      }
    }*/
    if(!ans[i]) ans[i] = org[i];
  }

  int count = 0;
  for(int i=1;i<=n;i++) count += ans[i] == org[i];

  cout << count << endl;
  for(int i=1;i<=n;i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
  
int main() {
  int t; cin >> t;
  while(t--) solve();
}
