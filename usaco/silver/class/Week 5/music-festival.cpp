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
  int n, a, b;
  cin >> n;
  vector<pair<int, int>> movies;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    movies.push_back({b, a});
  }
  sort(all(movies));
  int curEnd = -1;
  int ans = 0;
  for (auto p : movies) {
    if (p.second >= curEnd) {
      curEnd = p.first;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}