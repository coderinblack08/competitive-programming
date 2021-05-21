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

const int MOD = 1e9 + 7;

struct mi {
  int v;
  explicit operator int() const { return v; }
  mi(ll _v) : v(_v % MOD) { v += (v < 0) * MOD; }
  mi() : mi(0) {}
};
mi operator+(mi a, mi b) { return mi(a.v + b.v); }
mi operator-(mi a, mi b) { return mi(a.v - b.v); }
mi operator*(mi a, mi b) { return mi((ll)a.v * b.v); }

int n;
vector<pair<int, int>> v;
vector<mi> sum[100005];
vector<pair<int, int>> todo[20001];

void check() {
  for (int i = 0; i <= 20000; i++) {
    int sz = todo[i].size();
    if (todo[i].size() > 0) {
      sort(all(todo[i]));
      mi cur = 0;
      for (int j = 0; j < sz; j++) {
        cur = cur + todo[i][j].first - todo[i][0].first;
      }
      for (int j = 0; j < sz; j++) {
        if (j) {
          cur = cur + (2 * j - sz) * (todo[i][j].first - todo[i][j - 1].first);
        }
        sum[todo[i][j].second].push_back(cur);
      }
    }
  }
}

int main() {
  setIO("triangles");
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  for (int i = 0; i <= 20000; i++) {
    todo[i].clear();
  }
  for (int i = 0; i < n; i++) {
    todo[v[i].first + 10000].push_back({v[i].second, i});
  }
  check();
  for (int i = 0; i <= 20000; i++) {
    todo[i].clear();
  }
  for (int i = 0; i < n; i++) {
    todo[v[i].second + 10000].push_back({v[i].first, i});
  }
  check();
  mi ans = 0;
  for (int i = 0; i < n; i++) {
    ans = ans + sum[i][0] * sum[i][1];
  }
  cout << ans.v << endl;
  return 0;
}