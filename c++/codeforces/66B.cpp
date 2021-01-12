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
  vector<int> v(n);
  for (auto& a : v) cin >> a;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    int l = i, r = i;
    while (l > 0) {
      if (v[l] >= v[l - 1]) {
        cnt++;
        l--;
      } else {
        break;
      }
    }
    while (r < n - 1) {
      if (v[r] >= v[r + 1]) {
        cnt++;
        r++;
      } else {
        break;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}