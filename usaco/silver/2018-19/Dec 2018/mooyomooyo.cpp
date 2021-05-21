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

int n, k;
int board[101][10];
bool vis[101][10];

void dfs(int x, int y, int color, int& count) {
  if (x < 0 || x >= n || y < 0 || y >= 10) return;
  if (vis[x][y]) return;
  if (board[x][y] != color) return;
  vis[x][y] = true;
  count++;

  dfs(x - 1, y, color, count);
  dfs(x + 1, y, color, count);
  dfs(x, y - 1, color, count);
  dfs(x, y + 1, color, count);
}

void pop(int x, int y, int color) {
  if (x < 0 || x >= n || y < 0 || y >= 10) return;
  if (board[x][y] != color) return;
  board[x][y] = 0;

  pop(x - 1, y, color);
  pop(x + 1, y, color);
  pop(x, y - 1, color);
  pop(x, y + 1, color);
}

void gravity() {
  for (int i = 0; i < 10; i++) {
    queue<int> q;
    for (int j = n - 1; j >= 0; j--) {
      if (board[j][i] == 0) {
        q.push(j);
      } else if (!q.empty()) {
        board[q.front()][i] = board[j][i];
        board[j][i] = 0;
        q.push(j);
        q.pop();
      }
    }
  }
}

int main() {
  setIO("mooyomooyo");
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 10; j++) {
      board[i][j] = s[j] - '0';
    }
  }

  bool popped = true;
  while (popped) {
    popped = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 10; j++) {
        if (board[i][j] == 0) continue;
        if (vis[i][j]) continue;
        int count = 0;
        dfs(i, j, board[i][j], count);
        if (count >= k) {
          popped = true;
          pop(i, j, board[i][j]);
        }
      }
    }
    gravity();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 10; j++) {
        vis[i][j] = false;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
  return 0;
}
