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
  ll n, k;
  cin >> n >> k;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll count = 0;
    for (ll j = 0; j < n; j++) {
      if (A[j] >= A[i] && A[j] <= A[i] + k) {
        count++;
      }
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
  return 0;
}