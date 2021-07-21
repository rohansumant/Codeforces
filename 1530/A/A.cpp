#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int x; cin >> x;
    int ans = 1;
    while(x) {
      ans = max(ans,x%10);
      x /= 10;
    }
    cout << ans << endl;
  }
}
