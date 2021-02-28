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

const int MX = 1e5;
int n, m;
int x[MX], y[MX];
vector<int> adj[MX], comp[MX];
int c = 0;
bool vis[MX];

void dfs(int node) {
  if (vis[node]) return;
  vis[node] = true;
  comp[c].push_back(node);
  for (int u : adj[node]) {
    if (!vis[u]) {
      dfs(u);
    }
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
      c++;
    }
  }
}

int main() {
  setIO("fenceplan");
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int j = 0; j < m; j++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  solve();
  int ans = INT_MAX;
  for (int i = 0; i < c; i++) {
    int x1 = INT_MAX, x2 = 0, y1 = INT_MAX, y2 = 0;
    for (int u : comp[i]) {
      x1 = min(x1, x[u]);
      x2 = max(x2, x[u]);
      y1 = min(y1, y[u]);
      y2 = max(y2, y[u]);
    }
    ans = min(ans, (x2 - x1) + (y2 - y1));
  }
  cout << ans * 2 << endl;
  return 0;
}