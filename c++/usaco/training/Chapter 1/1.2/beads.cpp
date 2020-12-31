/*
ID: kevinlu4
TASK: beads
LANG: C++11
*/

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
string s;

int collect(char bead, bool left) {
  int len = 0;
  if (left) {
    for (ll i = n - 1; i >= 0; i--) {
      if (s[i] == bead || s[i] == 'w') {
        len++;
      } else {
        break;
      }
    }
  } else {
    for (ll i = 0; i < n; i++) {
      if (s[i] == bead || s[i] == 'w') {
        len++;
      } else {
        break;
      }
    }
  }
  return len;
}

int main() {
  setIO("beads");
  cin >> n >> s;
  string og = s;
  int ans = 0;
  do {
    int l = 0, r = 0;
    const char beads[2] = {'r', 'b'};
    for (char i : beads) {
      l = max(l, collect(i, true));
      r = max(r, collect(i, false));
      cerr << l << " " << r << " " << i << endl;
    }
    if (l + r > n) {
      ans = n;
    } else {
      ans = max(ans, l + r);
    }
    cerr << l << " " << r << " " << s << endl;
    s = s[n - 1] + s.substr(0, n - 1);
  } while (og != s);
  cout << ans << endl;
  return 0;
}