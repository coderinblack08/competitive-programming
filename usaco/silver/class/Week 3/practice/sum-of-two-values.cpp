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
  int n, x;
  cin >> n >> x;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  int l = 0, r = n - 1;
  while (l < r) {
    ll cur = a[l].first + a[r].first;
    if (cur < x) {
      l++;
    } else if (cur > x) {
      r--;
    } else {
      cout << a[l].second + 1 << " " << a[r].second + 1;
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
}