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
vector<int> p, ans;
bool cycle;

void gen(int x) {
  if (ans[x] != -2) {
    if (ans[x] == -1) {
      ans[x] = x;
      cycle = true;
    }
    return;
  }
  ans[x] = -1;
  gen(p[x]);
  if (ans[x] != -1) {
    cycle = false;
    return;
  }
  ans[x] = cycle ? x : ans[p[x]];
}

int main() {
  setIO();
  cin >> n;
  p.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  ans.assign(n, -2);
  for (int i = 0; i < n; i++) {
    gen(i);
  }
  for (auto x : ans) cout << x + 1 << " ";
  return 0;
}