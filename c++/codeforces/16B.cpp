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

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

int main() {
  setIO();
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(m);
  for (auto& a : v) cin >> a.first >> a.second;
  sort(all(v), cmp);
  int tot = 0;
  for (auto& a : v) {
    cerr << a.first << " " << a.second << endl;
    if (a.first > n) {
      tot += n * a.second;
      break;
    }
    tot += a.second * a.first;
    n -= a.first;
  }
  cout << tot << endl;
  return 0;
}