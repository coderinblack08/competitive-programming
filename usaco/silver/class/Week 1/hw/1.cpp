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
  setIO("div7");
  int n, ans = 0;
  cin >> n;
  map<int, int> mp;
  vector<int> psum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    psum[i] = (psum[i - 1] + x) % 7;
    if (mp.count(psum[i])) {
      ans = max(ans, i - mp[psum[i]]);
    } else {
      mp[psum[i]] = i;
    }
  }
  cout << ans << endl;
  return 0;
}