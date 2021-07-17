#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,k; cin >> n >> k;
  assert(k == 2);
  int xor_sum = 0;
  bool found = false;
  for(int i=0;i<n;i++) {
    int want_to_ask = i;
    int need_to_ask = xor_sum ^ want_to_ask;
    cout << need_to_ask << endl;
    cout.flush();
    int result;
    cin >> result;
    if(!result) {
      xor_sum ^= need_to_ask;
    } else {
      found = true;
      break;
    }
  }
  if(!found) assert(0);
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
