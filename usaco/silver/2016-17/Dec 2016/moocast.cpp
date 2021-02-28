#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
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

const int MX = 201;
int x[MX], y[MX], p[MX];
bool adj[MX][MX];
bool vis[MX];
int n;

int dfs(int node) {
  vis[node] = true;
  int cows = 0;
  for (int j = 0; j < n; j++) {
    if (vis[j] || !adj[node][j]) continue;
    vis[j] = true;
    cows += dfs(j) + 1;
  }
  return cows;
}

int main() {
  setIO("moocast");
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> p[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dist = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
      if (dist <= pow(p[i], 2)) {
        adj[i][j] = true;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    fill(all(vis), false);
    int hear = dfs(i) + 1;
    ans = max(ans, hear);
  }
  cout << ans << endl;
  return 0;
}