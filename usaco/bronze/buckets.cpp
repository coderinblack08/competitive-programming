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
  setIO("buckets");
  char c;
  pair<ll, ll> B, R, L;
  for (ll i = 0; i < 10; i++) {
    for (ll j = 0; j < 10; j++) {
      cin >> c;
      if (c == 'B') {
        B.first = i;
        B.second = j;
      } else if (c == 'R') {
        R.first = i;
        R.second = j;
      } else if (c == 'L') {
        L.first = i;
        L.second = j;
      }
    }
  }
  ll distBL = abs(B.first - L.first) + abs(B.second - L.second);
  ll distBR = abs(B.first - R.first) + abs(B.second - R.second);
  ll distRL = abs(R.first - L.first) + abs(R.second - L.second);
  if ((B.first == L.first || B.second == L.second) && distBL == distBR + distRL) {
    cout << distBL + 1;
  } else {
    cout << distBL - 1;
  }
  return 0;
}
