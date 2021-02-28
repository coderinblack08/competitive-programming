#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, x = 0, y = 0, z = 0;
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    ll x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    x += x1;
    y += y1;
    z += z1;
  }
  if (x == 0 && y == 0 && z == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}