#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
#define f first
#define s second
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
  setIO("bcount");
  ll n, q;
  cin >> n >> q;
  vector<ll> h(n + 1, 0), g(n + 1, 0), j(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    g[i + 1] = g[i];
    h[i + 1] = h[i];
    j[i + 1] = j[i];
    ll id;
    cin >> id;
    if (id == 1) {
      h[i + 1]++;
    } else if (id == 2) {
      g[i + 1]++;
    } else {
      j[i + 1]++;
    }
  }

  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << h[r] - h[l - 1] << " " << g[r] - g[l - 1] << " " << j[r] - j[l - 1] << endl;
  }
  return 0;
}