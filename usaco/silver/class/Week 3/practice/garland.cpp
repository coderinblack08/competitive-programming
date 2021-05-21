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

int main() {
  setIO();
  string s;
  int n, q;
  cin >> n >> s >> q;
  for (int i = 0; i < q; i++) {
    int m, maximum = 0;
    char c;
    cin >> m >> c;
    int l = 0, r = 0;
    while (l < n && r < n) {
      while (r < n) {
        if (s[r] != c) {
          if (m == 0) break;
          m--;
        }
        r++;
      }
      maximum = max(maximum, r - l);
      m += s[l++] != c;
    }
    cout << maximum << endl;
  }
  return 0;
}