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
  ll a, b, c, m;
  cin >> a >> b >> c >> m;
  vector<pair<ll, bool>> v;
  for (ll i = 0; i < m; i++) {
    ll val;
    string type;
    cin >> val >> type;
    if (type == "USB") {
      v.push_back({val, false});
    } else {
      v.push_back({val, true});
    }
  }
  sort(all(v));
  ll mc = 0, ans = 0;
  for (auto z : v) {
    if (z.second == 0) {
      if (a) {
        a--;
        mc++;
        ans += z.first;
      } else if (c) {
        c--;
        mc++;
        ans += z.first;
      }
    } else {
      if (b) {
        b--;
        mc++;
        ans += z.first;
      } else if (c) {
        c--;
        mc++;
        ans += z.first;
      }
    }
  }
  cout << mc << " " << ans << endl;
  return 0;
}