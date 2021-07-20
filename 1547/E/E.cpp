#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,k; cin >> n >> k;
  const int INF = 2e9+5;
  vector<int> a(n,INF);
  typedef pair<int,int> pii;
  priority_queue<pii,vector<pii>,greater<pii>> Q;
  {
    vector<int> b(k);
    for(int i=0;i<k;i++) cin >> b[i];
    for(int i=0;i<k;i++) {
      int ix = b[i]-1;
      int temp; cin >> temp;
      Q.push({temp,ix});
    }
  }
  while(!Q.empty()) {
    auto [temp,ix] = Q.top();
    Q.pop();
    if(a[ix] == INF) {
      a[ix] = temp;
    } else continue; // no need to visit again
    for(int nix : {ix-1, ix+1}) {
      if(nix >= 0 && nix < n && a[nix] == INF) {
        Q.push({temp+1,nix});
      }
    }
  }
  
  for(int i=0;i<n;i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}


int main() {
  int t; cin >> t;
  while(t--) solve();
}
