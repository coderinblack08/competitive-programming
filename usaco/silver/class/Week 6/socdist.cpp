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
  setIO("socdist");
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> A(m);
  for (ll i = 0; i < m; i++) {
    cin >> A[i].first >> A[i].second;
  }
  sort(all(A));
  ll lo = 0, hi = 1e18;
  while (lo < hi) {
    ll d = lo + (hi - lo + 1) / 2;
    ll last = -1e18;
    ll placed = 0;
    for (ll i = 0; i < m; i++) {
      ll first = max(last + d, A[i].first);
      if (first > A[i].second) continue;
      ll space = A[i].second - first;
      ll can_place = space / d;
      placed += can_place + 1;
      last = first + can_place * d;
    }
    if (placed >= n) {
      lo = d;
    } else {
      hi = d - 1;
    }
  }
  cout << lo;
  return 0;
}