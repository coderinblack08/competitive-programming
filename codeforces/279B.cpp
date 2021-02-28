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
int A[MX];

int main() {
  setIO();
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int r = -1, ans = 0;
  for (int l = 0; l < n; l++) {
    while (r + 1 < n && t >= A[r + 1]) t -= A[++r];
    ans = max(ans, r - l + 1);
    if (r == l - 1)
      r++;
    else
      t += A[l];
  }
  cout << ans << endl;
  return 0;
}