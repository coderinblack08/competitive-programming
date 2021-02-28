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

int n, m, c;

bool works(vector<int> &t, int mid) {
  int buses = 1;
  int time = t[0];
  int index = 0;
  for (int i = 1; i < n; i++) {
    if (t[i] - time > mid || i + 1 - index > c) {
      buses += 1;
      time = t[i];
      index = i;
    }
  }
  return buses <= m;
}

int main() {
  setIO("convention");
  cin >> n >> m >> c;
  vector<int> t(n);
  for (auto &c : t) cin >> c;
  sort(all(t));
  int lo = 0, hi = 1e9;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (works(t, mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
  return 0;
}