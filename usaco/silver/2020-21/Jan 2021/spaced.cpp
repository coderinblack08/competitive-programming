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
  setIO();
  int n;
  cin >> n;
  int grid[n][n];
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      cin >> grid[y][x];
    }
  }
  ll h = 0;
  for (int y = 0; y < n; y++) {
    ll s[2];
    s[0] = 0;
    s[1] = 0;
    for (int x = 0; x < n; x++) {
      s[x % 2] += grid[y][x];
    }
    h += max(s[0], s[1]);
  }
  ll v = 0;
  for (int x = 0; x < n; x++) {
    ll s[2];
    s[0] = 0;
    s[1] = 0;
    for (int y = 0; y < n; y++) {
      s[y % 2] += grid[y][x];
    }
    v += max(s[0], s[1]);
  }
  cout << max(h, v) << endl;
  return 0;
}