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
  int n;
  cin >> n;
  vector<double> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  sort(all(a)), sort(all(b));
  double total_a = 0, total_b = 0;
  double ans = 0;
  int index = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    total_a += a[i];
    total_b--;
    double x = min(total_a, total_b);
    ans = max(ans, min(total_a, total_b));
    while (index >= 0 && total_b < total_a) {
      total_a--;
      total_b += b[index];
      index--;
      ans = max(ans, min(total_a, total_b));
    }
    ans = max(ans, min(total_a, total_b));
  }
  printf("%.4lf", (double)ans);
  return 0;
}