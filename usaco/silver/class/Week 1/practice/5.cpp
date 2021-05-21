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

int n, psum[2501][2501];
pair<int, int> p[2500];

bool comp(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int getSum(int fromX, int toX, int fromY, int toY) {
  return psum[toX][toY] - psum[fromX - 1][toY] - psum[toX][fromY - 1] + psum[fromX - 1][fromY - 1];
}

int main() {
  setIO();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    p[i].first = i + 1;
  }
  sort(p, p + n, comp);
  for (int i = 0; i < n; i++) {
    p[i].second = i + 1;
  }
  for (int i = 0; i < n; i++) {
    psum[p[i].first][p[i].second] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
    }
  }
  ll ans = n + 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int x1 = min(p[i].first, p[j].first);
      int x2 = max(p[i].first, p[j].first);
      int y1 = min(p[i].second, p[j].second);
      int y2 = max(p[i].second, p[j].second);
      ans += getSum(x1, x2, 1, y1) * getSum(x1, x2, y2, n);
    }
  }
  cout << ans << endl;
  return 0;
}