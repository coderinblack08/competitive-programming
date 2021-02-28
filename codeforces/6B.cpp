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
  char c;
  char G[100][100];
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> G[i][j];
    }
  }
  set<char> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (G[i][j] == c) {
        for (int a = -1; a <= 1; a++) {
          for (int b = -1; b <= 1; b++) {
            if (i + a >= 0 && i + a < n) {
              if (j + b >= 0 && j + b < m) {
                if (a == -1 && b != 0) continue;
                if (a == 1 && b != 0) continue;
                if (G[i + a][j + b] != '.' && G[i + a][j + b] != c) {
                  s.insert(G[i + a][j + b]);
                }
              }
            }
          }
        }
      }
    }
  }
  cout << s.size() << endl;
  return 0;
}