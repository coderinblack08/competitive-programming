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

int n = 0, ax = 0, ay = 0, bx = 0, by = 0, cx = 0, cy = 0;
bool ans = false;

bool ok(int x, int y) {
  if (x == ax || y == ay) return false;
  int slope = abs(ax - ay);
  int neg_slope = ax + ay;
  if (abs(x - y) == slope || x + y == neg_slope) return false;
  return true;
}

bool vis[1001][1001];

void dfs(int x, int y) {
  if (x > n || x < 1 || y > n || y < 1 || vis[x][y]) return;
  if (x == cx && y == cy) {
    ans = true;
    return;
  }
  vis[x][y] = true;
  int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  for (int i = 0; i < 8; i++) {
    if (ok(x + dx[i], y + dy[i]) && !vis[x + dx[i]][y + dy[i]]) {
      dfs(x + dx[i], y + dy[i]);
    }
  }
}

int main() {
  setIO();
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
  dfs(bx, by);
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}