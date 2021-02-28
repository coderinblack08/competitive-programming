#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll n, m;
string grid[2500];
bool visited[2500][2500];

const ll xd[4] = {0, 1, 0, -1};
const ll yd[4] = {1, 0, -1, 0};

void floodfill(ll x, ll y) {
  if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || visited[x][y]) {
    return;
  }
  visited[x][y] = true;
  for (ll i = 0; i < 4; i++) {
    floodfill(x + xd[i], y + yd[i]);
  }
}

int main() {
  cin >> n >> m;
  for (ll i = 0; i < n; i++) {
    cin >> grid[i];  // read in the grid
  }
  ll ans = 0;
  // go through every unit in the grid
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      // if it is not a wall and we have not visited it yet
      // we found a new room
      if (grid[i][j] == '.' && !visited[i][j]) {
        floodfill(i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}