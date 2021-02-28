#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int main() {
  setIO("cbarn");
  ll n;
  cin >> n;
  vector<ll> v(n), w(n, 0);
  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      w[i] += v[(i + j) % n] * j;
    }
  }
  ll ans = w[0];
  for (auto c: w) {
    ans = min(ans, c);
  }
  cout << ans;
  return 0;
}