#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("revegetate");
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> A(m);
  vector<ll> G(m);
  for (ll i = 0; i < m; ++i) {
    cin >> A[i].first >> A[i].second;
    if (A[i].first > A[i].second) swap(A[i].first, A[i].second);
  }
  for (ll i = 1; i <= n; ++i) {
    ll g;
    for (g = 1; g <= 4; ++g) {
      bool ok = true;
      for (ll k = 0; k < m; ++k) {
        if (A[k].second == i && G[A[k].first] == g) ok = false;
      }
      if (ok) break;
    }
    G[i] = g;
    cout << g;
  }
  cout << "\n";
  return 0;
}