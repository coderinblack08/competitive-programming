#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("diamond");
  ll n, k, ans = 0;
  cin >> n >> k;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; ++i) cin >> A[i];
  for (ll i = 0; i < n; ++i) {
    ll counter = 0;
    for (ll j = 0; j < n; ++j) {
      if (A[j] >= A[i] && A[j] <= A[i] + k) {
        counter++;
      }
    }
    ans = max(ans, counter);
  }
  cout << ans << "\n";
  return 0;
}