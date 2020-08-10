#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 1e9 + 7;
ll POW(ll b, ll e, ll m) {
  if(e == 0) return 1LL;
  else if (e % 2 == 0) {
    return POW((b * b) % m, e / 2, m);
  } else {
    return (b * POW(b, e - 1, m) % m);
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  for (ll  i = 0; i < n; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, POW(b, c, MOD - 1), MOD) << "\n";
  }
  return 0;
}