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

const int MX = 2e5 + 5;

int n, q;
int A[MX];
ll psum[MX], ipsum[MX];

void prefix(int x) {
  for (int i = x; i < n; i++) {
    psum[i + 1] = psum[i] + A[i] * pow(-1, i);
    ipsum[i + 1] = ipsum[i] + A[i] * (i + 1) * pow(-1, i);
  }
}

int main() {
  setIO();
  int t;
  cin >> t;
  for (int test = 1; test <= t; test++) {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    ll sol = 0;
    prefix(0);
    while (q--) {
      char type;
      cin >> type;
      int l, r;
      cin >> l >> r;
      if (type == 'Q') {
        ll cur = ipsum[r] - ipsum[l - 1] - (l - 1) * (psum[r] - psum[l - 1]);
        cur = cur * pow(-1, l - 1);
        sol += cur;
      } else {
        l--;
        A[l] = r;
        prefix(l);
      }
    }
    cout << "Case #" << test << ": " << sol << endl;
  }
  return 0;
}