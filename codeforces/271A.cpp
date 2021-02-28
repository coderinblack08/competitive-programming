#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  for (ll i = n + 1;; ++i) {
    set<ll> digits;
    for (ll j = 0; j < 4; ++j) {
      digits.insert(to_string(i)[j] - '0');
    }
    if (digits.size() == 4) {
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}