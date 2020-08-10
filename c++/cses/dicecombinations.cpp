#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = (1e9 + 7);
vector<ll> DP;
vector<bool> SN;

ll sv(ll n) {
  ll ans = 0;
  if (n == 0) return 1;
  if (n < 0) return 0;
  if(SN[n]) return DP[n];
  for (ll i = 1; i <= 6; i++) {
    ans = (ans + sv(n - i)) % MOD;
  }
  SN[n] = true;
  DP[n] = ans;
  return ans;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  DP = vector<ll>(n, 0);
  SN = vector<bool>(n, false);
  cout << sv(n) << "\n";
  return 0;
}