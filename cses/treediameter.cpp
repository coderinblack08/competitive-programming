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

const int MX = 2e5 + 1;

int n, dist[MX];
vector<int> adj[MX];

void dfs(int x, int p) {
  for (auto &c : adj[x]) {
    if (c != p) {
      dist[c] = dist[x] + 1;
      dfs(c, x);
    }
  }
}

void dfs(int x) {
  memset(dist, 0, sizeof dist);
  dfs(x, -1);
}

int tree_diameter() {
  dfs(1);
  int best = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[best]) {
      best = i;
    }
  }
  dfs(best);
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[best]) {
      best = i;
    }
  }
  return dist[best];
}

int main() {
  setIO();
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cout << tree_diameter() << endl;
  return 0;
}