#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
  vector<pair<ll, ll>> timeline;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    timeline.push_back({a, 1});
    timeline.push_back({b, -1});
  }
  sort(all(timeline));  // when you sort a vector of pairs, they sort increasing by the first value
  ll sum = 0, ans = 0;
  for (pair<ll, ll> &x : timeline) {
    sum += x.second;
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}