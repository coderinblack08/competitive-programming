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
  ll n, m;
  cin >> n >> m;
  multiset<ll> tickets;
  for (ll i = 0; i < n; i++) {
    ll h;
    cin >> h;
    tickets.insert(h);
  }
  for (ll i = 0; i < m; i++) {
    ll t;
    cin >> t;
    auto it = tickets.upper_bound(t);
    if (it == tickets.begin()) {
      cout << -1 << endl;
    } else {
      cout << *(--it) << endl;
      tickets.erase(it);
    }
  }
  return 0;
}