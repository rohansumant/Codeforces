


/*

aaaabaaa
4 | 1
3 | 2
2 | 3
1 | 4

3 | 1
2 | 2
1 | 3



 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string ans = string(n/2,'a');
    ans += "b";
    ans += string(n - ans.size(), 'a');
    if(n & 1) {
      ans.pop_back();
      ans += "c";
    }
    cout << ans << endl;
  }
}


