#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();
  ll n;
  cin >> n;

  ll psum[n + 1] = {0}, A[n + 1];
  for (ll i = 1; i <= n; i++) {
    cin >> A[i];
  }

  for (ll i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + A[i];
  }

  ll ans = LONG_LONG_MIN;
  ll left = 0;

  for (ll r = 1; r <= n; r++) {
    ans = max(ans, psum[r] - left);
    left = min(left, psum[r]);
  }

  cout << ans;
}