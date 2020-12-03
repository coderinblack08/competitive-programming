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
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  ll best = 0;
  ll ans = 0;
  for (ll i = 2; i <= 1000; i++) {
    ll score = 0;
    for (ll j = 0; j < n; j++) {
      if (A[j] % i == 0) {
        score++;
      }
    }
    if (score > best) {
      best = score;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}