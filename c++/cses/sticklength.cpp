#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n; cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; ++i) cin >> A[i];
  sort(A.begin(), A.end());
  ll target = A[n / 2], cost = 0;
  for (ll i = 0; i < n; ++i) {
    cost += abs(target - A[i]);
  }
  cout << cost << "\n";
  return 0;
}