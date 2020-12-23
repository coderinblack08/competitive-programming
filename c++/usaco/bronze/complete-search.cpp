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
  ll n;
  cin >> n;
  ll ans = -1;
  vector<pair<ll, ll>> A(n);
  for (ll i = 0; i < n; i++) {
    cin >> A[i].first >> A[i].second;
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      ll dist = pow(A[i].first - A[j].first, 2) * pow(A[i].second - A[j].second, 2);
      ans = max(ans, dist);
    }
  }
  cout << ans << endl;
  return 0;
}