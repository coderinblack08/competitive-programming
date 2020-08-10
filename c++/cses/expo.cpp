#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 1e9 + 7;
ll MUL(ll x, ll y) {
  return (x * y) % MOD;
} 
ll POW(ll b, ll e) {
  if(e == 0) {
    return 1LL;
  } else if (e % 2 == 0) {
    return POW(MUL(b, b), e / 2);
  } else {
    return MUL(b, POW(b, e-1));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  for(ll i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    cout << POW(a, b) << "\n";
  }
  return 0;
}