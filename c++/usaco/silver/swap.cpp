#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> A(n + 1);
  vector<ll> visited(n + 1);
  for (ll i = 1; i <= n; i++) {
    A[i] = i;
  }
  for (ll i = 0; i < m; i++) {
    ll l, r;
    cin >> l >> r;
    for (ll j = 0; j < (r - l + 1) / 2; j++) {
      swap(A[i + j], A[r - j]);
    }
  }
  for (ll i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      ll start = A[i];
      vector<ll> cycle = {i};
      while (start != i) {
        cycle.push_back(i);
        start = A[start];
      }
      ll mod = k % cycle.size();
      for (ll j = 0; j < cycle.size(); j++) {
        A[cycle[j]] = cycle[(j + mod) % cycle.size()];
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    cout << A[i] << "\n";
  }
  return 0;
}