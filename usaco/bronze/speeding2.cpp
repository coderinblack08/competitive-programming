#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("speeding");
  ll n, m, ans = 0;
  vector<ll> road(101, 0);
  cin >> n >> m;
  ll pos = 0;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    for (ll j = pos; j < pos + a; j++) {
      road[j] = b;
    }
    pos += a;
  }
  pos = 0;
  for (ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    for (ll j = pos; j < pos + a; j++) {
      if (road[j] < b) {
        ans = max(ans, b - road[j]);
      }
    }
    pos += a;
  }
  cout << ans << endl;
  return 0;
}