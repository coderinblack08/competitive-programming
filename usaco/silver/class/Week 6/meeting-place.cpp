// CF 782B
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

int n;
const int MX = 6e4 + 1;
long double coords[MX], speed[MX];

bool canMeet(long double t) {
  long double max_left = 0, min_right = 2e9;
  for (int i = 0; i < n; i++) {
    long double l, r;
    long double pos = coords[i], vel = speed[i];
    l = pos - vel * t;
    r = pos + vel * t;
    max_left = max(max_left, l);
    min_right = min(min_right, r);
  }
  if (min_right < max_left) return false;
  return true;
}

int main() {
  setIO();
  cin >> n;
  for (int i = 0; i < n; i++) cin >> coords[i];
  for (int i = 0; i < n; i++) cin >> speed[i];
  long double l = 0, r = 1e9;

  while ((l + (1e-9)) < r) {  // add 1e-9 because of stupid float addition
    long double mid = (l + r) / 2;
    if (canMeet(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << setprecision(19) << l << endl;
  return 0;
}