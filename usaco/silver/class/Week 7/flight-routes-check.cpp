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

const int MX = 1e5 + 1;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
  if (vis[node]) return;
  vis[node] = true;
  for (auto& u : adj[node]) {
    dfs(u, adj, vis);
  }
}

int main() {
  setIO();
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<vector<int>> radj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    radj[b].push_back(a);
  }

  vector<bool> from(n, false);
  vector<bool> to(n, false);

  dfs(0, adj, from);
  dfs(0, radj, to);

  for (int i = 0; i < n; i++) {
    if (from[i] == false) {
      cout << "NO\n"
           << 1 << " " << i + 1 << '\n';
      return 0;
    }
    if (to[i] == false) {
      cout << "NO\n"
           << i + 1 << " " << 1 << '\n';
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}