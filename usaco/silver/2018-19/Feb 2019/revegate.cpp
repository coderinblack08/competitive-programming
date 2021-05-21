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
vector<int> s[MX], d[MX];
int vis[MX];
bool impossible;

void dfs(int node, int v) {
  vis[node] = v;
  for (int u : s[node]) {
    if (vis[u] == 3 - v) {
      impossible = true;
    }
    if (vis[u] == 0) {
      dfs(u, v);
    }
  }
  for (int u : d[node]) {
    if (vis[u] == 0) {
      dfs(u, 3 - v);
    }
    if (vis[u] == v) {
      impossible = true;
    }
  }
}

int main() {
  setIO("revegetate");
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    if (c == 'S') {
      s[a].push_back(b);
      s[b].push_back(a);
    } else {
      d[a].push_back(b);
      d[b].push_back(a);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 1);
      ans++;
    }
  }
  if (impossible) {
    cout << "0" << endl;
  } else {
    cout << "1";
    for (int i = 0; i < ans; i++) {
      cout << "0";
    }
    cout << endl;
  }
  return 0;
}