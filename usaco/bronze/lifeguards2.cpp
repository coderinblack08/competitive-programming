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
  setIO("lifeguards");
  ll n;
  cin >> n;
  vector<pair<ll, ll>> slots(n);
  for (ll i = 0; i < n; i++) {
    cin >> slots[i].first >> slots[i].second;
  }
  ll max_time = 0;
  for (ll i = 0; i < n; i++) {
    vector<int> covered(1001, false);
    for (ll j = 0; j < n; j++) {
      if (j != i) {
        for (ll k = slots[j].first; k < slots[j].second; k++) {
          covered[k] = true;
        }
      }
    }
    ll count = 0;
    for (ll j = 0; j < covered.size(); j++) {
      if (covered[j]) {
        count++;
      }
    }
    max_time = max(max_time, count);
  }
  cout << max_time << endl;
  return 0;
}