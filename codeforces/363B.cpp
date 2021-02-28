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
  int n, k;
  cin >> n >> k;
  vector<int> h(n), ps(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    ps[i + 1] = ps[i] + h[i];
  }
  int cur = INT_MAX;
  int ans = -1;
  for (int i = 0; i + k <= n; i++) {
    int sum = ps[i + k] - ps[i];
    if (sum < cur) {
      ans = i;
      cur = sum;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}