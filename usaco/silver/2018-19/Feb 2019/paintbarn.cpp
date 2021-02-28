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

const int MX = 1e3 + 1;

int v[MX][MX];

int main() {
  setIO("paintbarn");
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int j = a; j < c; j++) {
      v[j][b]++;
      v[j][d]--;
    }
  }
  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (v[i][j] == k) ans++;
      v[i][j + 1] += v[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}