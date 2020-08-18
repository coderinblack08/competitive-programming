#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll MOD = 1e9 + 7;
ll ADD(ll x, ll y) { return (x + y) % MOD; }

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; ++i) {
    cin >> A[i];
  }
  vector<ll> DP(x + 1, -1);
  DP[0] = 1LL;
  for (ll y = 1; y <= x; ++y) {
    ll dy = 0;
    for (ll a: A) {
      if (y - a >= 0) {
        dy += (dy, DP[y - a]);
      } 
    }
    DP[y] = dy % MOD;
  }
  cout << DP[x] << "\n";
  return 0;
}