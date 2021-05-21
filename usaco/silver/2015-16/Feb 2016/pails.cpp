#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

bool vis[101][101][101];
int x, y, k, m, ans;

void floodfill(int curX, int curY, int curK) {
  if (vis[curX][curY][curK] || curK > k) {
    return;
  }
  vis[curX][curY][curK] = true;

  ans = min(ans, abs(m - (curX + curY)));

  floodfill(x, curY, curK + 1);
  floodfill(curX, y, curK + 1);

  floodfill(0, curY, curK + 1);
  floodfill(curX, 0, curK + 1);

  int leftX = (curX + curY > y ? curX + curY - y : 0);
  int leftY = (curX + curY > x ? curX + curY - x : 0);

  floodfill(leftX, min(y, curY + curX), curK + 1);
  floodfill(min(x, curY + curX), leftY, curK + 1);
}

int main() {
  setIO("pails");
  cin >> x >> y >> k >> m;

  ans = m;
  floodfill(0, 0, 0);
  cout << ans << endl;
  return 0;
}