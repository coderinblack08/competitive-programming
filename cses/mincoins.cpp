#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

vector<ll> DP;

ll dp (ll n, const vector<ll> &A) {
  if (n < 0) return 1e12;
  if (n == 0) return 0LL;
  if (DP[n] >= 0) return DP[n];
  ll ans = 1e12;
  for (ll i = 0; i < A.size(); ++i) {
    ans = min(ans, 1 + dp(n - A[i], A));
  }
  DP[n] = ans;
  return ans;
} 

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n, 0);

  for (ll i = 0; i < n; ++i) {
    cin >> A[i];
  }
  DP = vector<ll>(x + 1, -1);
  ll ans = dp(x, A);
  cout << (ans >= 1e12 ? -1: ans);
  return 0;
}