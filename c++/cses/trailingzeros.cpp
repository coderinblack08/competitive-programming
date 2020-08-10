#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, ans = 0;
  cin >> n;
  for(ll i = 1;; ++i) {
    if(n / pow(5, i) > 0) {
      ans += n / pow(5, i);
    } else {
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}