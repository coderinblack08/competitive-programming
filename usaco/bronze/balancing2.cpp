#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("balancing");
  ll n, b;
  cin >> n >> b;
  ll m = n;
  vector<pair<ll, ll>> grid(n);
  for (ll i = 0; i < n; i++) {
    cin >> grid[i].first >> grid[i].second;
  }
  for (ll A = 0; A < b; A += 2) {
    for (ll B = 0; B < b; B += 2) {
      ll ne = 0, es = 0, sw = 0, nw = 0;
      for (pair<ll, ll> coord : grid) {
        if (coord.first > A && coord.second > B) {
          ne++;
        }
        if (coord.first > A && coord.second < B) {
          es++;
        }
        if (coord.first < A && coord.second < B) {
          sw++;
        }
        if (coord.first < A && coord.second > B) {
          nw++;
        }
      }
      m = min(m, max(max(ne, es), max(sw, nw)));
    }
  }
  cout << m << endl;
  return 0;
}