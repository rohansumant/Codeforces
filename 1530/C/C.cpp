#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
static int debug = 0;
#else
static int debug = 0;
#endif

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  for(int i=1;i<n;i++) {
    a[i] += a[i-1];
    b[i] += b[i-1];
  }

  auto get = [](const vector<int> &v, int count) {
    if(!count) return 0;
    return v[count-1];
  };

  int L = -1, R = n*3;

  while(L+1 < R) {
    int M = (L+R)/2;
    int total = n + M;
    int me = get(a,n) + 100*M - get(a,total/4);
    int ilya = get(b,n) - get(b,max(0,total/4 - M));
    if(debug) {
      printf("%d %d | %d %d %d\n",me,ilya,L,M,R);
    }
    if(me >= ilya) {
      R = M;
    } else {
      L = M;
    }
  }
  cout << R << endl;
}

int main() {
  int t; cin >> t;
  for(int i=0;i<t;i++) solve();
}
