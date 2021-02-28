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
  setIO("shell");
  ll n, ans = 0;
  cin >> n;
  vector<ll> A(n), B(n), G(n);
  for (ll i = 0; i < n; i++) {
    cin >> A[i] >> B[i] >> G[i];
  }
  for (ll i = 1; i <= 3; i++) {
    ll at = i, c = 0;
    for (ll j = 0; j < n; j++) {
      bool skip = false;
      if (at == A[j]) {
        at = B[j];
        skip = true;
      }
      if (at == B[j] && !skip) {
        at = A[j];
      }
      if (at == G[j]) {
        c++;
      }
    }
    ans = max(ans, c);
  }
  cout << ans << endl;
  return 0;
}