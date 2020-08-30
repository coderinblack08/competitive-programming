#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("cowtip");
  string k;
  ll n, ans = 0;
  cin >> n;
  vector<vector<ll>> G(n, vector<ll>(n));
  for (ll i = 0; i < n; ++i) { 
    cin >> k; 
    for (ll j = 0; j < n; ++j) G[i][j] = k[j];
  }
  for (ll i = n - 1; i >= 0; --i) {
    for (ll j = n - 1; j >= 0; --j) {
      if (G[i][j] == '1') {
        ans++;
        for (ll k = 0; k <= i; ++k) {
          for (ll m = 0; m <= j; ++m) {
            if (G[k][m] == '1') G[k][m] = '0';
            else G[k][m] = '1';
          }
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}