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

/*
int main() {
  setIO("div7");
  ll n;
  cin >> n;
  vector<ll> v(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    ll id;
    cin >> id;
    if (i == 0) {
      v[i + 1] = id;
    } else {
      v[i + 1] = v[i] + id;
    }
  }
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= i; j++) {
      // cerr << v[i] << " " << v[j - 1] << endl;
      if ((v[i] - v[j - 1]) % 7 == 0) {
        ans = max(ans, i - j + 1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

Analysis: this approach is too slow since O(n ^ 2) can be up to 2,500,000,000 (thus fails on test case 9 & 10)
*/

// to speed the problem up, we can use a hashmap

int main() {
  setIO("div7");
  ll n, ans = 0;
  cin >> n;
  vector<ll> v(n + 1, 0);
  set<ll> s = {0};  // seen set
  map<ll, ll> m;    // keep track of index
  for (ll i = 0; i < n; i++) {
    ll id;
    cin >> id;
    v[i + 1] = (v[i] + id) % 7;  // prefix sum, can simplify by using mod everytime

    if (s.count(v[i + 1])) {
      ll dist = i - m[v[i + 1]];
      ans = max(ans, dist);
    } else {
      s.insert(v[i + 1]);
      m[v[i + 1]] = i;
    }
  }
  cout << ans << endl;
}