#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n;
  cin >> n;
  vector<pll> A(n - 1);
  for (ll i = 0; i < n - 1; ++i) cin >> A[i].first >> A[i].second;
  
  return 0;
}