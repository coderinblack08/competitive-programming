#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll m, n;
  cin >> m >> n;
  vector<ll> digits(10, 0);
  for (ll i = m; i <= n; i++) {
    ll x = i;
    while (x) {
      digits[x % 10]++;
      x /= 10;
    }
  }
  for (auto digit : digits) {
    cout << digit << " ";
  }
  return 0;
}