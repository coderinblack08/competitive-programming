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

const int MX = 3e3 + 1;
vector<int> adj[MX];
bool vis[MX], closed[MX];
int order[MX];
int n, m, nodes = 0;

void dfs(int node) {
  if (vis[node] || closed[node]) return;
  nodes++;
  vis[node] = true;
  for (int u : adj[node]) {
    if (!vis[u]) {
      dfs(u);
    }
  }
}

int main() {
  setIO("closing");
  cin >> n >> m;
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    cin >> order[i];
  }
  dfs(1);
  if (nodes == n)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  for (int i = 0; i < n - 1; i++) {
    fill(all(vis), false);
    nodes = 0;
    closed[order[i]] = true;
    dfs(order[n - 1]);
    if (nodes == n - i - 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}