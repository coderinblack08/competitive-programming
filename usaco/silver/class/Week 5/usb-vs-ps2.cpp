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
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  vector<pair<int, string>> mouse(m);
  for (int i = 0; i < m; i++) cin >> mouse[i].first >> mouse[i].second;
  sort(all(mouse));
  ll count = 0;
  ll cost = 0;
  for (int i = 0; i < m; i++) {
    if (mouse[i].second == "USB" && a > 0) {
      cost += mouse[i].first;
      count++;
      a--;
    } else if (mouse[i].second == "PS/2" && b > 0) {
      cost += mouse[i].first;
      count++;
      b--;
    } else if (c > 0) {
      cost += mouse[i].first;
      count++;
      c--;
    }
  }
  cout << count << " " << cost;
  return 0;
}