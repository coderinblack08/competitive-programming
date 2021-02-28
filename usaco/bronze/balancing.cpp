#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("balancing");
  ll n;
  cin >> n;
  vector<pair<ll, ll>> A(n);
  for (ll i = 0; i < n; ++i) cin >> A[i].first >> A[i].second;
  ll ans = n;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < n; ++j) {
      ll x = A[i].first + 1, y = A[j].second + 1;
      ll upper_right = 0, lower_right = 0, upper_left = 0, lower_left = 0;
      for (auto& cow: A) {
        if (cow.first > x && cow.second > y) {
          upper_right++;
        } else if (cow.first > x && cow.second < y) {
          lower_right++;
        } else if (cow.first < x && cow.second > y) {
          upper_left++;
        } else {
          lower_left++;
        }
      }
      ans = min(ans, max(max(upper_left, lower_left), max(upper_right, lower_right)));
    }
  }
  cout << ans;
  return 0;
}