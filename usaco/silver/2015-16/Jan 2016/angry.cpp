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
  setIO("angry");
  int n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (auto &c : v) cin >> c;

  sort(all(v));

  ll low = 0, high = 1e9;
  while (low < high) {
    ll mid = low + (high - low) / 2;
    int used = 0;
    int last = 0;
    while (last < n) {
      used++;
      int cur = last + 1;
      // from each center x + r, we can go from x --> x + 2r
      while (cur < n && v[cur] - v[last] <= 2 * mid) {
        cur++;
      }
      last = cur;
    }
    if (used <= k) {
      high = mid;
      // perfect, now try lower values
    } else {
      low = mid + 1;
      // too low, try higher values
    }
  }
  cout << low << endl;
  return 0;
}