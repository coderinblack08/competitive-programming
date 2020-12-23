#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll grid[2005][2005];
int main() {
  ll n, ans = LONG_LONG_MAX;
  cin >> n;
  for (ll i = 0; i < 2005; i++) {
    for (ll j = 0; j < 2005; j++) {
      grid[i][j] = -1;
    }
  }
  ll x = 1000, y = 1000, t = 0;
  for (ll i = 0; i < n; i++) {
    char c;
    ll s;
    cin >> c >> s;
    for (ll j = 0; j < s; j++) {
      if (c == 'N') {
        y--;
      }
      if (c == 'E') {
        x++;
      }
      if (c == 'S') {
        y++;
      }
      if (c == 'W') {
        x--;
      }
      if (grid[i][j] != -1) {
        ans = min(ans, t - grid[i][j]);
      }
      grid[i][j] = t;
      t++;
    }
  }
  cout << ans << endl;
  return 0;
}