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
  int n, m;
  cin >> n >> m;
  vector<int> cities(n), towers(m);
  for (int i = 0; i < n; i++) {
    cin >> cities[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> towers[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int right = lower_bound(all(towers), cities[i]) - towers.begin();
    int left = right - 1;

    int r = 2e9;
    if (right < m) {
      r = min(r, towers[right] - cities[i]);
    }
    if (left >= 0) {
      r = min(r, cities[i] - towers[left]);
    }

    ans = max(ans, r);
  }
  cout << ans;
  return 0;
}