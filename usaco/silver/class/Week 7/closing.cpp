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

const int MAX_N = 3e3 + 1;
int n, m;
vector<int> adj[MAX_N];
bool vis[MAX_N], open[MAX_N];

void dfs(int x) {
  vis[x] = true;
  for (int c : adj[x]) {
    if (!vis[c]) dfs(c);
  }
}

int get_comps() {
  memset(vis, false, n);
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i] || open[i]) dfs(i);
  }
  return c;
}

void solve() {
  int comps = get_comps();
  if (comps == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  setIO();
  cin >> n >> m;
  memset(open, true, n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  solve();
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    adj[a].clear();
    open[a] = false;
    solve();
  }
  return 0;
}