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
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; ++i) cin >> A[i];
  set<ll> S;
  ll start = 0, ans = 0;
  for (ll i = 0; i < n; ++i) {
    while (S.count(A[i])) {
      S.erase(A[start]);
      start++;
    }
    S.insert(A[i]);
    ans = max(ans, i - start + 1);
  }
  cout << ans << "\n";
  return 0;
}