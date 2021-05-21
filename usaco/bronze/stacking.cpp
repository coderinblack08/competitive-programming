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
  vector<int> v(n + 1);
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    v[l]++;
    v[r + 1]--;
  }
  int ans[n];
  int tot = 0;
  for (int i = 0; i < n; i++) {
    tot += v[i];
    ans[i] = tot;
  }
  sort(ans, ans + n);
  cout << ans[n / 2] << endl;
  return 0;
}