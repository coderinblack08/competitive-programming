#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
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

ll n;
void check(ll& ans, ll i, vector<ll>& a, vector<ll>& b) {
  ans = max(ans, a[i] + b[n] - b[i]);
}

int main() {
  setIO("hps");
  cin >> n;
  vector<ll> h(n + 1), p(n + 1), s(n + 1);
  for (ll i = 0; i < n; i++) {
    h[i + 1] = h[i];
    p[i + 1] = p[i];
    s[i + 1] = s[i];

    char cur;
    cin >> cur;
    if (cur == 'P') {
      p[i + 1]++;
    } else if (cur == 'H') {
      h[i + 1]++;
    } else {
      s[i + 1]++;
    }
  }
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    check(ans, i, h, p);
    check(ans, i, h, s);
    check(ans, i, p, s);
    check(ans, i, p, h);
    check(ans, i, s, h);
    check(ans, i, s, p);
  }
  cout << ans << endl;
  return 0;
}