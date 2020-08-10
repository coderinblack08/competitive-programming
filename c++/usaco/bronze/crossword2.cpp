#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  freopen("crosswords.in", "r", stdin);
  freopen("crosswords.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  char G[n][m];
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      cin >> G[i][j];
    }
  }
  vector<pair<ll, ll>> S;
  for (ll r = 0; r < n; ++r) {
    for (ll c = 0; c < m; ++c) {
      if (G[r][c] == '.') {
        if ((c == 0 || (c != 0 && G[r][c - 1] == '#')) && G[r][c + 1] == '.' && G[r][c + 2] == '.' && c + 2 < m) {
          S.push_back(make_pair(r + 1, c + 1));
        }
        else if ((r == 0 || (r != 0 && G[r - 1][c] == '#')) && G[r + 1][c] == '.' && G[r + 2][c] == '.' && r + 2 < n) {
          S.push_back(make_pair(r + 1, c + 1));
        }
      }
    }
  }
  cout << S.size() << "\n";
  for (auto clue: S) {
    cout << clue.first << " " << clue.second << "\n";
  }
  return 0;
}