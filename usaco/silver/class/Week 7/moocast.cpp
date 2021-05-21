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

int n;
const int MX = 1e3 + 1;
int x[MX], y[MX];
bool visited[MX], g[MX][MX];

int dfs(int v) {
  visited[v] = true;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] || !g[v][i]) continue;
    cur += dfs(i);
  }
  return cur + 1;
}

bool ok(ll mid) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = false;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      if (dist <= mid) g[i][j] = true;
    }
  }
  fill(visited, visited + n, false);
  int cows = dfs(0);
  return cows == n;
}

int main() {
  setIO("moocast");
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  ll lo = 1, hi = 1e10;
  ll ans = hi;
  while (lo <= hi) {
    ll mid = lo + (hi - lo) / 2LL;
    if (ok(mid)) {
      ans = min(ans, mid);
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}