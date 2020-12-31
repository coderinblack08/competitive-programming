/*
ID: kevinlu4
TASK: gift1
LANG: C++  
*/

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
  setIO("gift1");
  int np;
  cin >> np;
  unordered_map<string, int> mp;
  vector<string> order;
  for (ll i = 0; i < np; i++) {
    string a;
    cin >> a;
    mp[a] = 0;
    order.push_back(a);
  }
  for (ll i = 0; i < np; i++) {
    string a;
    int b, c;
    cin >> a >> b >> c;
    if (c == 0) {
      continue;
    }
    mp[a] -= b - (b % c);
    int split = b / c;
    for (ll j = 0; j < c; j++) {
      cin >> a;
      mp[a] += split;
    }
  }
  for (auto& a : order) {
    cout << a << " " << mp[a] << endl;
  }
  return 0;
}