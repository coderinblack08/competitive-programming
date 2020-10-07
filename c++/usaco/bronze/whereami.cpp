#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("whereami");
  ll n;
  string s;
  cin >> n >> s;
  for (ll i = 1; i <= n; i++) {
    set<string> S;
    for (ll j = 0; j + i <= n; j++) {
      string s2 = s.substr(j, i);
      if (S.count(s2)) {
        break;
      } else {
        if (j + i == n) {
          cout << i << "\n";
          return 0;
        }
        S.insert(s2);
      }
    }
  }
  cout << n << "\n";
  return 0;
}