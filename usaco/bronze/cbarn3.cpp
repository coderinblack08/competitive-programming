#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n;
  cin >> n;
  vector<ll> R(n);
  for (ll i = 0; i < n; i++) {
    cin >> R[i];
  }
  ll ans = LONG_LONG_MAX;
  for (ll i = 0; i < n; i++) {
    ll c = 0;
    for (ll j = 0; j < n; j++) {
      ll cur = (j + i) % n;
      c += j * R[cur];
    }
    ans = min(ans, c);
  }
  cout << ans << endl;
  return 0;
}