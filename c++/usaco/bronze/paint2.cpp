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
  setIO("paint");
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<int> paint(101, false);
  for (ll i = a; i < b; i++) {
    paint[i] = true;
  }
  for (ll i = c; i < d; i++) {
    paint[i] = true;
  }
  ll ans = 0;
  for (ll i = 0; i < 100; i++) {
    if (paint[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}