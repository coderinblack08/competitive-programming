#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("outofplace");
  ll n, ans = 0; cin >> n;
  vector<ll> A(n), B(n);
  for (ll i = 0; i < n; ++i) { cin >> A[i]; B[i] = A[i]; }
  sort(B.begin(), B.end());
  for (ll i = 0; i < n; ++i) {
    if (A[i] != B[i]) ans++;
  }
  cout << ans - 1;
  return 0;
}