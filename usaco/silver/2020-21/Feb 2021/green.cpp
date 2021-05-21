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

int N;
bool ok[1000][1000];

ll solve() {
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    vector<bool> all_ones(N, true);
    for (int j = i; j < N; ++j) {
      // add rectangles with upper row i and lower row j
      int run = 0;
      for (int k = 0; k < N; ++k) {
        // all_ones_{i,j-1}[k] -> all_ones_{i,j}[k]
        all_ones[k] = all_ones[k] & ok[j][k];
        if (all_ones[k]) {
          ans += ++run;  // update answer
          cout << i << " " << j << " " << k << " " << run << " true" << endl;
        } else {
          run = 0;
          cout << i << " " << j << " " << k << " " << run << " false" << endl;
        }
      }
    }
  }
  return ans;
}

int main() {
  setIO();
  cin >> N;
  vector<vector<int>> pasture(N, vector<int>(N));
  for (vector<int>& a : pasture)
    for (int& b : a) cin >> b;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      ok[i][j] = pasture[i][j] >= 100;
  ll ans = solve();

  cout << ans << "\n";
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      ok[i][j] = pasture[i][j] > 100;
  ans -= solve();

  cout << ans << "\n";
}
