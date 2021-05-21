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

int n;
char board[25][25][3];
bool vis[25][25][19683];

void dfs(int i, int j, int b) {
  if (vis[i][j][b]) return;
  vis[i][j][b] = true;
  if (board[i][j][0] == 'M' || board[i][j][0] == 'O') {
    int r = board[i][j][1] - '1';
    int c = board[i][j][2] - '1';
    int index = r * 3 + c;
    int cur = (b / int(pow(3, index))) % 3;
  }
};

int main() {
  int bessie_i, bessie_j, bstate = 0;
  setIO();
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j][0] >> board[i][j][1] >> board[i][j][2];
      if (board[i][j][0] == 'B') {
        bessie_i = i;
        bessie_j = j;
      }
    }
  }
  dfs(bessie_i, bessie_j, bstate);
  return 0;
}