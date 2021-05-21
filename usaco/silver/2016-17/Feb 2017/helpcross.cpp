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
  setIO("helpcross");
  int c, n;
  cin >> c >> n;
  multiset<int> chickens;
  pair<int, int> cows[n];
  for (int i = 0; i < c; i++) {
    int x;
    cin >> x;
    chickens.insert(x);
  }
  for (int i = 0; i < n; i++) {
    cin >> cows[i].second >> cows[i].first;
  }
  sort(cows, cows + n);
  int ans = 0;
  for (int j = 0; j < n; j++) {
    auto which = chickens.lower_bound(cows[j].second);
    if (which != chickens.end() && *which <= cows[j].first) {
      ans++;
      chickens.erase(which);
    }
  }
  cout << ans << endl;
  return 0;
}