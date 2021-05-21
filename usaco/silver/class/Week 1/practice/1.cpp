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
  int n, q;
  cin >> n >> q;
  ll psum[n + 1], a[n];
  psum[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    psum[i + 1] = psum[i] + a[i];
  }
  for (int i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    cout << psum[r] - psum[l] << endl;
  }
  return 0;
}