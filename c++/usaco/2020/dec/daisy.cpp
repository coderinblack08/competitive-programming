#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll n;
  cin >> n;
  vector<ll> P(n);
  for (ll i = 0; i < n; i++) {
    cin >> P[i];
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = i; j < n; j++) {
      ll count = 0;
      for (ll k = i; k <= j; k++) {
        count += P[k];
      }
      double average = (double)count / (j - i + 1);
      for (ll k = i; k <= j; k++) {
        if ((double)P[k] == average) {
          ans += 1;
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}