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
  setIO("gymnastics");
  ll k, n;
  cin >> k >> n;
  ll A[k][n];
  for (ll i = 0; i < k; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  ll pairs = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      ll count = 0;
      for (ll a = 0; a < k; a++) {
        ll foundA, foundB;
        for (ll b = 0; b < n; b++) {
          if (A[a][b] == i) {
            foundA = b;
          }
          if (A[a][b] == j) {
            foundB = b;
          }
        }
        if (foundA < foundB) {
          count++;
        }
      }
      if (count == k) {
        pairs++;
      }
    }
  }
  cout << pairs << "\n";
  return 0;
}