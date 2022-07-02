// https://codeforces.com/contest/1543/problem/C

#include <bits/stdc++.h>
using namespace std;

bool equals(double a,double b) {
  double diff = abs(a-b);
  return (diff <= 1e-8);
}

double calc(int iter, double c,
    double m, double p, double v) {

  double ans = iter*p;
  double diff;
  //printf("%d %f %f %f\n",iter,c,m,p);
  if(!equals(c,0) && !equals(m,0)) {
    diff = min(c,v);
    ans += c*calc(iter+1,c-diff,m+diff/2,p+diff/2,v);

    diff = min(m,v);
    ans += m*calc(iter+1,c+diff/2,m-diff,p+diff/2,v);
  } else if(!equals(c,0)) {
    diff = min(c,v);
    ans += c*calc(iter+1,c-diff,m,p+diff,v);
  } else if(!equals(m,0)) {
    diff = min(m,v);
    ans += m*calc(iter+1,c,m-diff,p+diff,v);
  } else {
    equals(p,1);
  }
  return ans;
}

void solve() {
  double c,m,p,v;
  cin >> c >> m >> p >> v;
  double ans = calc(1,c,m,p,v);
  printf("%.10f\n",ans);
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
