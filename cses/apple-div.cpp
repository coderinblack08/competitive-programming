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

int n, k;

bool works(vector<ll> &v, ll x) {
  int groups = 0;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] > x) {
      return false;
    }
    if (sum + v[i] > x) {
      groups++;
      sum = 0;
    }
    sum += v[i];
  }
  if (sum > 0) {
    groups++;
  }
  return groups <= k;
}

int main() {
  setIO();
  cin >> n >> k;

  vector<ll> v(n);
  for (auto &c : v) cin >> c;

  ll low = 0, high = 1e18, ans = 0;
  while (low <= high) {
    ll mid = (low + high) / 2;
    if (works(v, mid)) {
      high = mid - 1;
      ans = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}