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
  setIO();
  ll n;
  cin >> n;
  ll lo = 1, hi = n * n;
  while (lo < hi) {
    ll mid = (lo + hi) / 2, count = 0;
    for (int i = 1; i <= n; i++) count += min(n, mid / i);
    if (count >= (n * n + 1) / 2)
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << hi << endl;
  return 0;
}