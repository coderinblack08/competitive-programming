#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll find_cow(vector<string> &names, string s) {
  for (ll i = 0; i < names.size(); ++i) {
    if (names[i] == s) {
      return i;
    }
  }
  return -1;
}

int main() {
  setIO("notlast");
  ll n, a;
  cin >> n;
  vector<string> names = {
    "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"
  };
  vector<ll> v(names.size(), 0);
  for (ll i = 0; i < n; ++i) {
    string s;
    cin >> s >> a;
    v[find_cow(names, s)] += a;
  }
  ll low = LONG_LONG_MAX, second = LONG_LONG_MAX;
  for (auto c: v) {
    low = min(low, c);
  }
  for (auto c: v) {
    if (c > low && c < second) {
      second = c;
    }
  }
  ll ans = -1;
  bool found = false;
  for (ll i = 0; i < n; ++i) {
    if (v[i] == second && found == false) {
      ans = i;
      found = true;
    } else if (v[i] == second && found) {
      cout << "tie\n";
      return 0;
    }
  }
  if (ans >= 0) {
    cout << names[ans] << "\n";
  } else {
    cout << "tie\n";
  }
  return 0;
}