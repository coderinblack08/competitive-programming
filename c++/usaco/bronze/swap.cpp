#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, a1, a2, b1, b2, r[101];

ll next(ll a) {
  if (a1 <= a && a <= a2)
    a = a1 + a2 - a;
  if (b1 <= a && a <= b2)
    a = b1 + b2 - a;
  return a;
}

ll main() {
  freopen("swap.in", "r", stdin);
  freopen("swap.out", "w", stdout);
  cin >> n >> k >> a1 >> a2 >> b1 >> b2;
  for (ll i = 1; i < n + 1; ++i) {
    ll p = 1, c = next(i);
    while (c != i) {
      ++p;
      c = next(c);
    }
    ll after = k % p;
    for (ll j = 0; j < after; j++) {
      c = next(c);
    }
    r[c] = i;
  }
  for (ll i = 1; i < n + 1; ++i) {
    cout << r[i] << "\n";
  }
  return 0;
}