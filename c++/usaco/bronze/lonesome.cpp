#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
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
  vector<pll> cows(n);
  for (ll i = 0; i < n; i++) {
    cin >> cows[i].first >> cows[i].second;
  }
  ll first, second;
  ll mx = -1;
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      ll dist = pow((cows[j].first - cows[i].first), 2) + pow((cows[j].second - cows[i].second), 2);
      if (dist > mx) {
        first = i + 1;
        second = j + 1;
        mx = dist;
      }
    }
  }
  cout << first << " " << second << "\n";
  return 0;
}