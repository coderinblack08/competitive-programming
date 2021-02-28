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
  setIO("teleport");
  ll a, b, x, y;
  cin >> a >> b >> x >> y;
  ll ans = abs(a - b);
  ans = min(ans, abs(a - x) + abs(b - y));
  ans = min(ans, abs(a - y) + abs(b - x));
  cout << ans << endl;
}