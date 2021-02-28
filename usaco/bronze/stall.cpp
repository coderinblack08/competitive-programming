#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int main() {
  setIO();
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &c : a) cin >> c;
  for (auto &c : b) cin >> c;

  sort(all(a));
  sort(all(b));

  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (a[i] <= b[j]) {
        v[i] = n - j;
        break;
      }
    }
  }

  ll ans = 1;
  for (ll i = 0; i < n; i++) {
    ans *= v[n - i - 1] - i;
  }
  cout << ans << endl;
  return 0;
}