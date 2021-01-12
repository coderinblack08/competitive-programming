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
  vector<ll> v(n);
  for (auto& a : v) cin >> a;
  vector<ll> t = v;
  sort(all(t));

  vector<pair<ll, ll>> ps(n, {0, 0});
  ps[0] = {v[0], t[0]};
  for (int i = 1; i < n; i++) {
    ps[i].first = ps[i - 1].first + v[i];
    ps[i].second = ps[i - 1].second + t[i];
    // cerr << i << " " << ps[i].first << " " << ps[i].second << endl;
  }

  int m;
  cin >> m;
  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      cout << ps[r - 1].first - ps[l - 1].first + v[l - 1] << endl;
    } else {
      cout << ps[r - 1].second - ps[l - 1].second + t[l - 1] << endl;
    }
  }
  return 0;
}