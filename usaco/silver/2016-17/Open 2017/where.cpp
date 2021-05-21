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
bool vis[20][20];
string img[20];
struct pcl {
  int x1, y1, x2, y2;
};
vector<pcl> v;

void visit(int i, int j, int c, pcl p) {
  vis[i][j] = true;
  if (i > p.x1 && img[i - 1][j] - 'A' == c && !vis[i - 1][j]) {
    visit(i - 1, j, c, p);
  }
  if (i < p.x2 && img[i + 1][j] - 'A' == c && !vis[i + 1][j]) {
    visit(i + 1, j, c, p);
  }
  if (j > p.y1 && img[i][j - 1] - 'A' == c && !vis[i][j - 1]) {
    visit(i, j - 1, c, p);
  }
  if (j < p.y2 && img[i][j + 1] - 'A' == c && !vis[i][j + 1]) {
    visit(i, j + 1, c, p);
  }
}

bool is_pcl(pcl p) {
  int cc = 0;
  int c[26] = {0};
  for (int i = p.x1; i <= p.x2; i++) {
    for (int j = p.y1; j <= p.y2; j++) {
      vis[i][j] = false;
    }
  }
  for (int i = p.x1; i <= p.x2; i++) {
    for (int j = p.y1; j <= p.y2; j++) {
      if (!vis[i][j]) {
        int cur = img[i][j] - 'A';
        if (c[cur] == 0) {
          cc++;
        }
        c[cur]++;
        visit(i, j, cur, p);
      }
    }
  }
  if (cc != 2) return false;
  bool found_one = false, found_many = false;
  for (int i = 0; i < 26; i++) {
    if (c[i] == 1) found_one = true;
    if (c[i] > 1) found_many = true;
  }
  return found_one && found_many;
}

bool PCL_IN_PCL(int x, int y) {
  return v[x].x1 >= v[y].x1 && v[x].x2 <= v[y].x2 && v[x].y1 >= v[y].y1 && v[x].y2 <= v[y].y2;
}

bool pcl_maximal(int x) {
  for (int i = 0; i < v.size(); i++) {
    if (i != x && PCL_IN_PCL(x, i)) {
      return false;
    }
  }
  return true;
}

int main() {
  setIO("where");
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> img[i];
  }
  for (int x1 = 0; x1 < n; x1++) {
    for (int y1 = 0; y1 < n; y1++) {
      for (int x2 = x1; x2 < n; x2++) {
        for (int y2 = y1; y2 < n; y2++) {
          pcl p = {x1, y1, x2, y2};
          if (is_pcl(p)) {
            v.push_back(p);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    if (pcl_maximal(i)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}