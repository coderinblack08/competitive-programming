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

const int MX = 1e5;

int num;
int comp[MX];
vector<int> adj[MX];

void dfs(int x) {
  if (comp[x]) return;
  comp[x] = num;
  for (auto &c : adj[x]) {
    dfs(c);
  }
}

int main() {
  setIO();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    adj[a].push_back(i);
    adj[i].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!comp[i]) {
      num++;
      dfs(i);
    }
  }
  // for (int i = 1; i <= n; i++) cout << comp[i] << endl;
  cout << num << endl;
  return 0;
}