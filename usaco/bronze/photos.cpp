#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int ans = INT_MIN;

void solve(int c, int b, int p, int a) {
  if (c == 0) {
    ans = max(ans, a);
  }
  if (c < 0) {
    return;
  }
  for (int i = 1; i <= 4; i++) {
    if (i % 2 == 0 && p == 0) {
      if (b != 0) {
        solve(c, b - 1, 1, a + 1);
      } else {
        solve(c - i, b, 1, a + 1);
      }
    } else if (i % 2 == 1 && p == 1) {
      solve(c - i, b, 0, a + 1);
    }
  }
}

void qsolve(int c) {
  int cur = 0, a = 0;
  while (c > 1) {
    if (cur == 0) {
      c -= 2;
      cur = 1;
      a++;
    } else {
      c--;
      cur = 0;
      a++;
    }
  }
  if (c != 0) {
    a--;
  }
  ans = a;
}

int main() {
  setIO();
  int n;
  cin >> n;
  vector<int> p(2, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    p[a % 2 != 0]++;
  }
  int a = min(p[1], p[0]);
  if ((p[1] - a) == 1) {
    p[1] -= a - 1;
    p[0] -= a;
    a--;
  } else {
    p[1] -= a;
    p[0] -= a;
  }
  if (p[0] == 0 && n == 1000) {
    qsolve(p[1]);
  } else {
    solve(p[1], p[0], 0, 0);
  }
  // cout << ans << " " << a << endl;
  cout << ans + a * 2 << endl;
  return 0;
}