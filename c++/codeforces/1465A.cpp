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
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    string s;
    cin >> n >> s;
    ll pos = -1;
    for (ll i = 0; i < n; i++) {
      if (s[i] == ')') {
        if (pos == -1) {
          pos = i;
        }
      } else {
        pos = -1;
      }
    }
    if (pos == -1 || n - pos <= pos) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}