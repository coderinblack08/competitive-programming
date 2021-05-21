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
string path;
const int MX = 4e3 + 3;
map<char, pair<int, int>> dir = {{'N', {0, 1}}, {'E', {1, 0}}, {'S', {0, -1}}, {'W', {-1, 0}}};
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int maxx = 2001, minx = 2001, maxy = 2001, miny = 2001;
bool farm[MX][MX], vis[MX][MX];

void floodfill(int i, int j) {
  if (i < minx || i > maxx || j < miny || j > maxy || vis[i][j] || farm[i][j]) {
    return;
  }
  vis[i][j] = true;
  for (int k = 0; k < 4; k++) {
    floodfill(i + dx[k], j + dy[k]);
  }
}

int main() {
  setIO("gates");
  cin >> n >> path;
  int x = 2001, y = 2001;
  for (int i = 0; i < n; i++) {
    farm[x + dir[path[i]].first][y + dir[path[i]].second] = true;
    farm[x + 2 * dir[path[i]].first][y + 2 * dir[path[i]].second] = true;
    x += 2 * dir[path[i]].first;
    y += 2 * dir[path[i]].second;
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
  }
  minx--;
  maxx++;
  miny--;
  maxy++;
  int regions = 0;
  for (int i = minx; i <= maxx; i++) {
    for (int j = miny; j <= maxy; j++) {
      if (!vis[i][j] && !farm[i][j]) {
        floodfill(i, j);
        regions++;
      }
    }
  }
  cout << regions - 1 << endl;
}