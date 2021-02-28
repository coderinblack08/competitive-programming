#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("moobuzz");
  ll n;
  cin >> n;
  ll lo = 0, hi = 5 * n;
  while (lo < hi) {
    ll mid = (lo + hi) / 2;
    ll x = mid - (mid / 3) - (mid / 5) + (mid / 15);
    if (x >= n) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
}