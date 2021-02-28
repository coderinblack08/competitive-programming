/*
ID: kevinlu4
TASK: milk2
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

int main() {
  setIO("milk2");
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, 1});
    v.push_back({b, -1});
  }
  sort(all(v));
  int cur = 0, idle = -1, cont = -1;
  pair<int, int> ans = {0, 0};
  for (int i = 0; i < 2 * n; i++) {
    pair<int, int> a = v[i];
    cur += a.second;
    // cerr << a.first << " " << a.second << " " << cur << " " << cont << endl;
    if (cur == 0) {
      if (idle == -1) {
        idle = a.first;
      }
      if (cont != -1) {
        ans.first = max(ans.first, a.first - cont);
        if (i != 2 * n - 1 && v[i + 1].first == a.first) {
          cont = cont;
        } else {
          cont = -1;
        }
      }
    } else {
      if (idle != -1) {
        ans.second = max(ans.second, a.first - idle);
        idle = -1;
      }
      if (cont == -1) {
        cont = a.first;
      }
    }
  }
  cout << ans.first << " " << ans.second << endl;
  return 0;
}