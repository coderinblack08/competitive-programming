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
const int MX = 1e5 + 1;
vector<int> adj[MX];

int dfs(int cur, int parent) {
  int children = 0;
  int cost = 0;
  for (int u : adj[cur]) {
    if (u == parent) {
      continue;
    }
    children++;
    cost += dfs(u, cur);
  }
  unsigned bits, var = (children < 0) ? -children : children;
  for (bits = 0; var != 0; ++bits) var >>= 1;
  cost += children + bits;
  return cost;
}

int main() {
  setIO();
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  cout << dfs(0, -1) << endl;
  return 0;
}