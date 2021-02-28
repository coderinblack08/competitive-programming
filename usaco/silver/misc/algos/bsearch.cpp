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

bool f(int x) {
  return x * x >= 30;  // range (-inf, -6] U [6, inf)
}

int first_true(int lo, int hi) {
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (f(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

int last_true(int lo, int hi) {
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (f(mid)) {
      lo = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

int main() {
  setIO();
  cout << first_true(4, 8) << endl;
  cout << last_true(4, 8) << endl;
  // 4, 5, 6, 7, 8
  // F, F, T, T, T
  //       |
  //    |
  // lo = hi, thus lo is answer
  return 0;
}