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

ll k, n;
ll rankings[10][20];

bool better(ll a, ll b, ll row) {
  ll apos, bpos;
  for (ll i = 0; i < n; i++) {
    if (rankings[row][i] == a) {
      apos = i;
    }
    if (rankings[row][i] == b) {
      bpos = i;
    }
  }
  return apos < bpos;
}

ll better_count(ll a, ll b) {
  ll count = 0;
  for (ll i = 0; i < k; i++) {
    if (better(a, b, i)) {
      count++;
    }
  }
  return count;
}

int main() {
  setIO("gymnastics");
  cin >> k >> n;
  for (ll i = 0; i < k; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> rankings[i][j];
    }
  }
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      if (better_count(i, j) == k) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}