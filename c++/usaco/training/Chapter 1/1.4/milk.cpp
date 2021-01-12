/*
ID: kevinlu4
TASK: milk
LANG: C++11
*/
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

int main() {
  setIO("milk");
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(all(v));
  int cost = 0;
  for (int i = 0; i < m && n; i++) {
    if (v[i].second < n) {
      n -= v[i].second;
      cost += v[i].first * v[i].second;
    } else {
      cost += n * v[i].first;
      n = 0;
    }
  }
  cout << cost << endl;
  return 0;
}