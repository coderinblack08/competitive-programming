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
int a[MX];
int n, m;

int ok(int x) {
  int sum = 0;
  for (int i = 0; i < x - 1; i++) {
    sum += a[i];
  }
  if (x > sum && x < sum + a[x - 1]) {
    return 0;
  } else if (x > sum + a[x - 1]) {
    return -1;
  } else if (x < sum) {
    return 1;
  }
}

int solve(int q) {
  int l = 1, h = n;
  while (l < h) {
    int mid = (l + h) / 2;
    cout << q << " " << mid << endl;
    int res = ok(mid);
    if (res == 0) {
      cout << mid << endl;
    } else if (res == 1) {
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
}

int main() {
  setIO();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int q;
    cin >> q;
    solve(q);
  }
  return 0;
}