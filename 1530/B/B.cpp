#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int R, C; cin >> R >> C;
  const int dr[] = {-1,-1,-1,0,0,1,1,1},
        dc[] = {-1,0,1,-1,1,-1,0,1};
  vector<vector<int>> a(R,vector<int>(C,0));

  auto valid = [R,C](int x,int y) {
    return min(x,y) >= 0 && x < R && y < C;
  };

  for(int r=0;r<R;r++) {
    for(int c=0;c<C;c++) {
      if(!r || !c || r == R-1 || c == C-1) {
        bool ok = true;
        for(int i=0;i<8;i++) {
          int nr = r+dr[i], nc = c+dc[i];
          if(valid(nr,nc) && a[nr][nc] == 1) {
            ok = false;
          }
        }
        if(ok) {
          a[r][c] = true;
        }
      }
      cout << a[r][c];
    }
    cout << endl;
  }
  cout << endl;
}
   

int main() {
  int t; cin >> t;
  while(t--) solve();
}
