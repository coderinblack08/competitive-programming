#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
#define MX 100000
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
int x[MX], y[MX];
int r[MX], l[MX];
int v[MX];

bool comp(int a, int b) {
  if (l[a] == l[b]) {
    return r[a] > r[b];
  }
  return l[a] < l[b];
}

int main() {
  setIO("mountains");
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    r[i] = x[i] + y[i];
    l[i] = x[i] - y[i];
    v[i] = i;
  }
  sort(v, v + n, comp);
  int max_pos = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (r[v[i]] > max_pos) {
      ans++;
      max_pos = r[v[i]];
    }
  }
  cout << ans << endl;
  return 0;
}