#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();
  int n;
  ll x;
  map<ll, int> mp;
  cin >> n >> x;
  vector<ll> v(n);
  mp[0]++;
  ll s = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    s += v[i];
    ans += mp[s - x];
    cerr << s - x << endl;
    mp[s]++;
    /* 
      mp = {
        2: 1,                                               i = 0
        1: 1,                                               i = 1 
        4: 1,                                               i = 2 
        9: 1, -> checks for 2, mp[2] = 1, adds 1 to ans     i = 3
        7: 1, -> checks for 0, mp[0] = 1, adds 1 to ans     i = 4
      }
    */
  }
  cout << ans << endl;
  return 0;
}