#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll MOD = 1e9+7;
ll ADD(ll x, ll y) { return (x + y) % MOD; }

vector<ll> DP;
ll dp(ll n) {
  ll ans = 0;
  if (n < 0) return 0;
  if (n == 0) return 1; 
  if (DP[n] >= 0) return DP[n];
  for (ll first = 1; first <= 6; ++first) {
    ans = ADD(ans, dp(n - first));
  }
   DP[n] = ans;
  return ans;
}

int main() {
  ll n;
  cin >> n;
  DP = vector<ll>(n + 1, -1);
  ll ans = dp(n);
  cout << ans << "\n";
  return 0;
}