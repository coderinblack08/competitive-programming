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

const int MX = 1e2;

int n, m;
int ans = 1;

bool lights[MX][MX], visited[MX][MX];
vector<pair<int, int>> change[MX][MX];

const int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

void floodfill(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= n || !lights[i][j] || visited[i][j]) return;

  visited[i][j] = true;

  if ((int)change[i][j].size() > 0) {
    for (auto c : change[i][j]) {
      if (!lights[c.first][c.second]) {
        lights[c.first][c.second] = true;
        ans++;
        for (int k = 0; k < 4; k++) {
          if (c.first + di[k] >= n || c.first + di[k] < 0) {
            continue;
          }
          if (c.second + dj[k] >= n || c.second + dj[k] < 0) {
            continue;
          }
          if (visited[c.first + di[k]][c.second + dj[k]]) {
            floodfill(c.first, c.second);
          }
        }
      }
    }
  }

  for (int k = 0; k < 4; k++) {
    floodfill(i + di[k], j + dj[k]);
  }
}

int main() {
  setIO("lightson");
  cin >> n >> m;
  lights[0][0] = true;

  for (int i = 0; i < m; i++) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    change[a - 1][b - 1].push_back({x - 1, y - 1});
  }

  floodfill(0, 0);

  cout << ans << endl;
  return 0;
}