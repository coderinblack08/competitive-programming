#include <bits/stdc++.h>
#define ll long long
#define MAX_N 12
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

ll n;
ll x[MAX_N + 1], y[MAX_N + 1], p[MAX_N + 1];
ll next_right[MAX_N + 1];

bool cycle_exists() {
  for (ll start = 1; start <= n; ++start) {
    ll pos = start;
    for (ll count = 0; count < n; ++count) {
      pos = next_right[p[pos]];
    }
    if (pos != 0) {
      return true;
    }
  }
  return false;
}

ll solve() {
  ll i, total = 0;
  for (i = 1; i <= n; ++i) {
    if (p[i] == 0) break;
  }
  if (i > n) {
    if (cycle_exists()) return 1;
    else return 0;
  }
  for (ll j = i + 1; j <= n; ++j) {
    if (p[j] == 0) {
      p[i] = j;
      p[j] = i;
      total += solve();
      p[i] = p[j] = 0;
    }
  }
  return total;
}

int main() {
  setIO("wormhole");
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
  }
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      if (x[j] > x[i] && y[i] == y[j]) {
        if (next_right[i] == 0 || x[j] - x[i] < x[next_right[i] - x[i]]) {
          next_right[i] = j;
        }
      }
    }
  }
  cout << solve() << "\n";
  return 0;
}