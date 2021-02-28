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

const int MX = 2e5 + 17;

vector<int> adj[MX];

double dfs(int x = 0, int p = -1) {
  double sum = 0;
  for (auto &c : adj[x]) {
    if (c != p) {
      sum += dfs(c, x) + 1;
    }
  }
  return sum ? sum / (adj[x].size() - (p != -1)) : 0;
}

int main() {
  setIO();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cout << fixed << setprecision(15) << dfs() << endl;
  return 0;
}