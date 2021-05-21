#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
#define vi vector<int>
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
  int n, x;
  cin >> n >> x;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  int ans = 0;
  for (int i = 0; i < n && x >= a[i]; i++) {
    ans++;
    x -= a[i];
  }
  cout << ans << endl;
  return 0;
}