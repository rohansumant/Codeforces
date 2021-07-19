#include <bits/stdc++.h>
using namespace std;

/*
 
   0 1 2 3 4
   6 9 1 9 6

   6 10 2 3 4 8
  -1 0 -1 2 3 4
 -1 -1 -1-1 


 0 1 2 3 4
 5 5 2 7
-1 0-1 2
-1-1-1 0 



 */
bool check(vector<int> &a,int st, int end) {
  int len = end - st + 1;
  if(len < 3) return true;
  for(int i=st;i<=end;i++) {
    for(int j=i+1;j<=end;j++) {
      for(int k=j+1;k<=end;k++) {
        if((a[i] <= a[j] && a[j] <= a[k])
            || (a[i] >= a[j] && a[j] >= a[k])) {
          return false;
      }
      }
    }
  }
  return true;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  long long ans = 0;
  for(int i=0;i<n;i++) {
    for(int j=i;j<min(n,i+4);j++) {
      if(check(a,i,j)) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}


