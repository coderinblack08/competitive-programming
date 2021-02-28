#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  for (ll i = 0; i < 5; ++i) {
    for (ll j = 0; j < 5; ++j) {
      cin >> t;
      if (t == 1) {
        cout << abs(2 - i) + abs(2 - j) << "\n";
      }
    }
  }
  return 0;
}