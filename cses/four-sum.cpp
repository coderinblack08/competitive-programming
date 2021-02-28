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
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n);
  unordered_map<ll, pair<ll, ll>> m;
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (ll i = n - 1; i >= 0; i++) {
    for (ll j = 0; j < i; j++) {
      auto p = x - A[i] - A[j];
      if (m.find(p) != m.end()) {
        cout << j + 1 << i + 1 << m[p].first + 1 << m[p].second + 1 << endl;
        return 0;
      }
    }
    for (ll j = i + 1; i < n; j++) {
      m[A[i] + A[j]] = {i, j};
    }
  }
  cout << "IMPOSSIBLE" << endl;
}