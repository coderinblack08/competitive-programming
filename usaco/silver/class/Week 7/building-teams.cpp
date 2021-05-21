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
int n, m;
vector<int> adj[MX];
bool bad, vis[MX], group[MX];

void dfs(int x = 1, bool color = 0) {
  vis[x] = true;
  group[x] = color;
  for (int u : adj[x]) {
    if (vis[u]) {
      if (group[u] == color) {
        bad = true;
      }
    } else {
      dfs(u, !color);
    }
  }
}

int main() {
  setIO();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; !bad && i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  if (bad) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    for (int i = 1; i <= n; i++) {
      cout << group[i] + 1 << " ";
    }
  }
  return 0;
}