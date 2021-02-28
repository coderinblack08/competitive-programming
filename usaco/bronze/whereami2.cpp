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
  string road;
  cin >> n >> road;
  for (ll i = 1; i <= n; i++) {
    set<string> s;
    bool passed = true;
    for (ll j = 0; j + i <= n; j++) {
      string section = road.substr(j, i);
      if (s.count(section)) {
        passed = false;
        break;
      }
      s.insert(section);
    }
    if (passed) {
      cout << i << endl;
      return 0;
    }
  }
}