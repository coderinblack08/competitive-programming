#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  freopen("marathon.in", "r", stdin);
  freopen("marathon.out", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vector< pair<ll, ll> > P(n, make_pair(0, 0));
  for (ll i = 0; i < n; ++i) {
    cin >> P[i].first >> P[i]. second;
  }
  ll sum = 0;
  for (ll i = 0; i < n - 1; ++i) {
    sum += abs(P[i].first - P[i + 1].first) + abs(P[i].second - P[i + 1].second);
  }
  ll msum = sum;
  for (ll i = 1; i < n - 1; ++i) {
    ll lsum = sum;
    lsum -= abs(P[i - 1].first - P[i].first) + abs(P[i - 1].second - P[i].second);
    lsum -= abs(P[i].first - P[i + 1].first) + abs(P[i].second - P[i + 1].second);
    lsum += abs(P[i - 1].first - P[i + 1].first) + abs(P[i - 1].second - P[i + 1].second);
    msum = min(msum, lsum);
  }
  cout << msum << "\n";
  return 0;
}