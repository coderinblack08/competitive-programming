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

const int MX = 1e5 + 10;
int n, m;
vector<int> adj[MX];
int rep[MX];
bool vis[MX];

void dfs(int node) {
  vis[node] = true;
  for (int c : adj[node]) {
    if (!vis[c]) {
      dfs(c);
    }
  }
}

int num_comp() {
  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      rep[c++] = i;
      dfs(i);
    }
  }
  return c;
}

int main() {
  setIO();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = num_comp();
  cout << ans - 1 << endl;
  for (int i = 1; i < ans; i++) {
    cout << rep[i - 1] << " " << rep[i] << endl;
  }
  return 0;
}