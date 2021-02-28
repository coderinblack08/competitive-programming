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
  ll c;
  cin >> c;
  for (ll i = 0; i < c; i++) {
    ll n, x;
    cin >> n >> x;
    ll floor = 1;
    while (2 + (floor - 1) * x < n) {
      floor++;
    }
    cout << floor << "\n";
  }
  return 0;
}