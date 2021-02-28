#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  map<ll, ll> m;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (ll i = 0; i < n; ++i) {
    if (m.count(x - a[i])) {
      cout << i + 1 << " " << m[x - a[i]] << "\n";
      return 0;
    }
    m[a[i]] = i + 1;
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}