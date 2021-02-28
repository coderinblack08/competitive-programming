
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  vector<vector<ll>> G(6, vector<ll>(6));
  for (ll i = 0; i < 6; ++i) {
    for (ll j = 0; j < 6; ++j) {
      cin >> G[i][j];
    }
  }
  ll ans = LONG_LONG_MIN;
  for (ll i = 0; i < 4; ++i) {
    for (ll j = 0; j < 4; ++j) {
      ll local = G[i][j] + G[i][j + 1] + G[i][j + 2] + G[i + 1][j + 1] + G[i + 2][j] + G[i + 2][j + 1] + G[i + 2][j +2];
      ans = max(local, ans);
    }
  }
  cout << ans << "\n";
  return 0;
}
