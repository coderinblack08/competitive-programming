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
  setIO("cownomics");
  ll n, m;
  cin >> n >> m;
  vector<string> spotty(n);
  vector<string> plain(n);
  for (ll i = 0; i < n; i++) {
    cin >> spotty[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> plain[i];
  }
  ll ans = 0;
  for (ll i = 0; i < m; i++) {
    set<char> has_spots;
    for (ll j = 0; j < n; j++) {
      has_spots.insert(spotty[j][i]);
    }
    bool worked = true;
    for (ll j = 0; j < n; j++) {
      if (has_spots.count(plain[j][i])) {
        worked = false;
        break;
      }
    }
    if (worked) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}