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
  ll lx = 0, sx = 10, ly = 0, sy = 10;
  ll x, y;
  for (ll i = 0; i < 4; i++) {
    cin >> x >> y;
    lx = max(x, lx);
    ly = max(y, ly);
    sx = min(x, sx);
    sy = min(y, sy);
  }
  ll rectLength = lx - sx, rectWidth = ly - sy;
  cout << pow(max(rectLength, rectWidth), 2) << "\n";
  return 0;
}