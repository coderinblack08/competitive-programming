#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

int is_ter(unsigned int x) {
  while (x > 1) {
    if (x % 2 == 0)
      x = x / 2;
    else if (x % 5 == 0)
      x = x / 5;
    else
      return 0;
  }
  return 1;
}

int main() {
  ll ans = 0;
  for (ll i = 0; i < 900; i++) {
    if (is_ter(i)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}