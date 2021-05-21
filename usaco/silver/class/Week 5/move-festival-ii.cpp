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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
  sort(all(v));
  int ans = 0;
  multiset<int> times;
  for (int i = 0; i < k; i++) times.insert(0);
  for (int i = 0; i < n; i++) {
    auto it = times.upper_bound(v[i].second);
    if (it == times.begin()) continue;
    times.erase(--it);
    times.insert(v[i].first);
    ans++;
  }
  cout << ans << endl;
  return 0;
}