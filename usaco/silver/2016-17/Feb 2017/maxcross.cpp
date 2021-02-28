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
  setIO("maxcross");
  int n, k, b;
  cin >> n >> k >> b;
  vector<int> status(n + 1, 0);
  for (int i = 0; i < b; i++) {
    int a;
    cin >> a;
    status[a] = 1;
  }
  vector<int> prefix(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + status[i];
  }
  int ans = k;
  for (int i = k; i <= n; i++) {
    ans = min(ans, prefix[i] - prefix[i - k]);
  }
  cout << ans << endl;
  return 0;
}