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

int p[1001][1001];

int main() {
  setIO();
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) {
      p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (s[j - 1] == '*');
    }
  }
  for (int i = 0; i < q; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << p[r2][c2] - p[r2][c1 - 1] - p[r1 - 1][c2] + p[r1 - 1][c1 - 1] << endl;
  }
  return 0;
}