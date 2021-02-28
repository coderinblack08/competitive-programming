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
const int MX = 1e5;

int v[MX], x[MX], y[MX], neg[MX], pos[MX];

bool comp(int a, int b) {
  if (neg[a] == neg[b]) {
    return pos[a] > pos[b];
  }
  return neg[a] < neg[b];
}

int main() {
  setIO("mountains");
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    pos[i] = x[i] + y[i], neg[i] = x[i] - y[i];
    v[i] = i;
  }
  sort(v, v + n, comp);
  int ans = 0;
  int highest = -1;
  for (int i = 0; i < n; i++) {
    if (pos[v[i]] > highest) {
      ans++;
      highest = pos[v[i]];
    }
  }
  cout << ans;
  return 0;
}