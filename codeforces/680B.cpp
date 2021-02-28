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
  int n, a;
  cin >> n >> a;
  vector<int> t(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (t[i]) {
      int d = i - a;
      int j = a - d;
      if (j < 1 || j > n || t[i] == t[j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}