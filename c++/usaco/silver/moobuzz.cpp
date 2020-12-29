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
  setIO("moobuzz");
  ll n;
  cin >> n;
  ll low = 0, high = 5 * n;
  while (low < high) {
    ll mid = (low + high) / 2;
    // cerr << mid << endl;
    ll ans = mid - (mid / 3) - (mid / 5) + (mid / 15);
    // number at mid (excluse the moo and use PIE)
    if (ans > n) {
      high = mid - 1;
    } else if (ans == n) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << endl;
  return 0;
}