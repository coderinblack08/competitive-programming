#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
} 

int main() {
  ll L = 1e6;
  vector<ll> F(L + 1, 0);
  for (ll d = 1; d <= L; ++d) {
    for (ll x = d; x <= L; x += d) {
      F[x]++;
    }
  }
  ll n, a;
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> a;
    cout << F[a] << "\n";
  }
  return 0;
}