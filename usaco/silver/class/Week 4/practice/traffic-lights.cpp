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
  ll x, n;
  cin >> x >> n;
  multiset<ll> lengths = {x};
  set<ll> lights = {0, x};
  for (ll i = 0, a; i < n; i++) {
    cin >> a;
    auto it = lights.upper_bound(a);
    ll upper = *(it--);
    ll lower = *it;
    lengths.erase(lengths.find(upper - lower));
    lengths.insert(upper - a);
    lengths.insert(a - lower);
    lights.insert(a);
    cout << *(lengths.rbegin()) << endl;
  }
  return 0;
}