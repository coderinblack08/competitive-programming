#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("pails");
  ll x, y, m;
  cin >> x >> y >> m;
  ll ans = 0;
  for (ll i = 0; i * y < m; ++i) {
    ll local = 0;
    local += i * y;
    local += ((m - local) / x) * x;
    ans = max(ans, local);
  }
  cout << ans;
  return 0;
}