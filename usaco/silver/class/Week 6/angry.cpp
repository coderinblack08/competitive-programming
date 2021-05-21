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

int n;
vector<int> A;

bool works_right(int start, int rad) {
  int cur = start, nex = 0;
  while (cur < A.back()) {
    while (nex + 1 < n && A[nex + 1] <= cur + rad) nex++;
    if (A[nex] == cur) {
      return false;
    }
    cur = A[nex];
    rad -= 2;
  }
  return true;
}

bool works_left(int start, int rad) {
  for (int &x : A) x *= -1;
  reverse(A.begin(), A.end());
  bool ans = works_right(-start, rad);
  reverse(A.begin(), A.end());
  for (int &x : A) x *= -1;
  return ans;
}

int main() {
  setIO("angry");
  cin >> n;
  A.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[i] *= 2;
  }
  sort(all(A));
  int lo = 0, hi = 2e9;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    int l = A.front(), r = A.back();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (works_right(m, mid)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    if (works_left(l, mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo / 2 << "." << (lo % 2 ? 5 : 0) << endl;
  return 0;
}