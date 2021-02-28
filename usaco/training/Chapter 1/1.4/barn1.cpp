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

int main() {
  setIO();
  int m, s, c;
  cin >> m >> s >> c;
  vector<int> occupied(m, false);
  for (int i = 0; i < c; i++) {
    int a;
    cin >> a;
    occupied[a - 1] = true;
  }
  int low = 0, high = m - 1;
  for (int i = 0; i < m && !occupied[i]; i++) {
    low++;
  }
  return 0;
}