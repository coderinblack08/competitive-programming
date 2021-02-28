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
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  for (auto& c : a) cin >> c;
  sort(all(a));
  double ans = 2 * max(a[0], l - a[n - 1]);
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, (double)a[i + 1] - a[i]);
  }
  cout << setprecision(10) << fixed << ans / 2 << endl;
  return 0;
}