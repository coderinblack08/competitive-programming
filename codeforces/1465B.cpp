#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    for (ll i = n;; i++) {
      bool works = true;
      ll temp = i;
      while (temp) {
        if (temp % 10) {
          if (i % (temp % 10) != 0) {
            works = false;
            break;
          }
        }
        temp /= 10;
      }
      if (works) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}