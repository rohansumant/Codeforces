#include <bits/stdc++.h>
using namespace std;

/*
 *
asd
asd

100 110
00 10

0010 1010 | 1000
100

011 101 | 110

 *:38 */

void solve() {
  int n,m; cin >> n >> m;
  int ans = 0;

  auto getbit = [](int x,int ix) {
    return x & (1<<ix) ? 1:0;
  };

  if(n <= m) {
    int xxor = n^m;
    for(int i=29;i>=0;i--) {
      int nx = getbit(n,i),
          mx = getbit(m,i),
          xx = getbit(xxor,i);
      if(xx) {
        if(nx) break;
        else {
          ans ^= (1<<i);
        }
      }
    }
    /*
     101 101 | 000

     */
    assert((n^ans) >= m);
    if((n^ans) == m) {
      int yy = (m^(m+1)) & (m+1);
      ans |= yy;
      ans &= -yy;
    }
    assert((n^ans) > m);
  }
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  for(int i=0;i<t;i++) solve();
}
