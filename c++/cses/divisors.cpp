#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fd(ll n) {
  ll ans = 0;
  for(int i = 1; i <= sqrt(n); ++i) {
    if(n % i == 0) {
      if(n / i == i) {
        ans ++;
      } else {
        ans += 2;
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    cout << fd(a) << "\n";
  }
  return 0;
}