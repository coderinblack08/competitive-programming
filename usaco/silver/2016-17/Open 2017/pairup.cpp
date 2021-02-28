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
  setIO("pairup");
  int n;
  cin >> n;
  vector<pair<ll, ll>> v;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    v.push_back({y, x});
  }
  sort(all(v));
  int left = 0, right = n - 1;
  ll ans = 0;
  while (left <= right) {
    int x = min(v[left].second, v[right].second);
    if (left == right) {
      x /= 2;
    }
    ans = max(ans, v[left].first + v[right].first);
    v[left].second -= x;
    v[right].second -= x;
    if (v[left].second == 0) {
      left++;
    }
    if (v[right].second == 0) {
      right--;
    }
  }
  cout << ans << endl;
  return 0;
}