#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll main() {
  ll n, k;
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> k;
    vector<ll> A(k);
    for (ll j = 0; j < k; ++j) {
      cin >> A[j];
    }
    ll ans = 0;
    for (ll i = A.size() - 1; i >= 0; i--) {
      if (A[i] - (i + 1) > 2) {
        cout << "Too chaotic" << endl;
        return;
      }
      for (ll j = max(0, A[i] - 2); j < i; j++)
        if (A[j] > A[i]) ans++;
      }
      cout << ans << endl;
    }
  return 0;
}