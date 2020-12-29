#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, ans = 0;
  cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> A[i] >> x;
    ans += x;
  }
  sort(all(A));
  ll f = 0;
  for (ll i = 0; i < n; i++) {
    f += A[i];
    ans -= f;
  }
  cout << ans << endl;
  return 0;
}