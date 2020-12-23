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
  setIO("triangle");
  ll n;
  cin >> n;
  vector<pair<ll, ll>> points(n);
  for (ll i = 0; i < n; i++) {
    cin >> points[i].first >> points[i].second;
  }
  ll max_area = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      for (ll k = 0; k < n; k++) {
        if (points[i].first == points[j].first && points[j].second == points[k].second) {
          ll y = points[i].second - points[j].second;
          ll x = points[k].first - points[j].first;
          ll current_area = abs(x * y);
          max_area = max(max_area, current_area);
        }
      }
    }
  }
  cout << max_area << endl;
  return 0;
}