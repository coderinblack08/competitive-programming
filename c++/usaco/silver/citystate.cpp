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
  setIO("citystate");
  ll n;
  cin >> n;
  map<string, ll> count;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    string city, state;
    cin >> city >> state;
    city = city.substr(0, 2);
    if (city != state) {
      ans += count[state + city];
    }
    count[city + state]++;
  }
  cout << ans << endl;
  return 0;
}