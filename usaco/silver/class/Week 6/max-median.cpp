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
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(all(A));
  ll l = 0, r = 2000000000;
  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    ll count = 0;
    for (int i = (n - 1) / 2; i < n; i++)
      count += max(0, mid - A[i]);
    if (count > (ll)k) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  cout << l;
  return 0;
}