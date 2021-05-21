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

bool comp(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second || (a.second == b.second && a.first < b.first);
}

int main() {
  setIO("sort");
  int n;
  cin >> n;
  pair<int, int> v[n];
  for (int i = 0; i < n; i++) {
    v[i].first = i;
    cin >> v[i].second;
  }
  sort(v, v + n, comp);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, v[i].first - i);
  }
  cout << ans + 1;
  return 0;
}