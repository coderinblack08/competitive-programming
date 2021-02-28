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

const int MX = 100005;

char col[MX];
vector<int> adj[MX];
int comp[MX], num;

void dfs(int x) {
  if (comp[x]) return;
  comp[x] = num;
  for (auto &a : adj[x]) {
    if (col[a] == col[x]) {
      dfs(a);
    }
  }
}

int main() {
  setIO("milkvisits");
  int n, m;
  string s;
  cin >> n >> m >> s;
  for (int i = 1; i <= n; i++) {
    col[i] = s[i - 1];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!comp[i]) {
      num++;
      dfs(i);
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    if (col[a] == c || comp[a] != comp[b]) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;
  return 0;
}