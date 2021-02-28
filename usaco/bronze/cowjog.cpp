#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  freopen("cowjog.in", "r", stdin);
  freopen("cowjog.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, t;
  cin >> n;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; ++i) {
    cin >> t >> A[i];
  }
  ll r = 1, s = A[n - 1];
  for (ll i = n - 2; i >= 0; --i) {
    if (A[i] <= s) {
      ++r;
    }
    s = min(s, A[i]);
  }
  cout << r << "\n";
  return 0;
}