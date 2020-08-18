#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, a, b;
  cin >> n;
  vector<pair<ll, ll>> A(n, {0, 0});
  for (ll i = 0; i < n; ++i) {
    cin >> A[i].second >> A[i].first;
  }
  sort(A.begin(), A.end());
  ll ans = 1;
  ll time = A[0].first;
  for (ll i = 1; i < n; ++i) {
    if (A[i].second >= time) {
      ans++;
      time = A[i].first;
    }
  }
  cout << ans << "\n";
  return 0;
}