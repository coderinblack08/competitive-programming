#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  for (ll i = 0; i < t; ++i) {
    ll a, b;
    cin >> a >> b;
    if ((2 * a - b) >= 0 && (2 * a - b) % 3 == 0 && (2 * b - a) >= 0 && (2 * b - a) % 3 == 0) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}