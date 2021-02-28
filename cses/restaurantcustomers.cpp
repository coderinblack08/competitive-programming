#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, s, e;
  cin >> n;
  vector<pair<ll, ll>> A;
  for (ll i = 0; i < n; ++i) {
    cin >> s >> e;
    A.push_back(make_pair(s, 1));
    A.push_back(make_pair(e, -1));
  }
  sort(all(A));
  ll ans = 0, counter = 0;
  for (auto c: A) {
    counter += c.second;
    ans = max(ans, counter);
  }
  cout << ans;
  return 0;
}