#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
#define f first
#define s second
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
bool cows[3000][3000];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void eval(int x, int y) {
  if (!cows[x][y]) return;
  int adj = 0;
  for (int d = 0; d < 4; d++) {
    adj += cows[x + dx[d]][y + dy[d]];
  }
  if (adj == 3) {
    for (int d = 0; d < 4; ++d) {
      pair<int, int> nex = {x + dx[d], y + dy[d]};
      if (!cows[nex.f][nex.s]) {
        q.push(nex);
      }
    }
  }
}

int main() {
  setIO();
  cin >> n;
  int total_cows = 0;
  for (int i = 1; i <= n; i++) {
    pair<int, int> p;
    cin >> p.f >> p.s;
    p.f += 1000;
    p.s += 1000;
    q.push(p);
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      if (cows[curr.f][curr.s]) {
        continue;
      }
      total_cows++;
      cows[curr.f][curr.s] = true;
      eval(curr.f, curr.s);
      for (int d = 0; d < 4; d++) {
        eval(curr.f + dx[d], curr.s + dy[d]);
      }
    }
    cout << total_cows - i << endl;
  }
  return 0;
}