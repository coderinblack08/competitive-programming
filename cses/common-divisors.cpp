#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  ll L = static_cast<ll>(1e6);
  vector<ll> COUNT(L + 1, 0);
  for (ll i = 0; i < n; ++i) {
    cin >> A[i];
    ++COUNT[A[i]];
  }
  for (ll d = L; d >= 0; --d) {
    ll count = 0;
    for (ll x = d; x <= L; x += d) {
      count += COUNT[x];
    }
    if (count >= 2) {
      cout << d << "\n";
      return 0;
    }
  }
  return 0;
}