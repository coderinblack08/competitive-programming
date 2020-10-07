#include <bits/stdc++.h>
#define ll long long
#define read(x) \
  ll x;         \
  cin >> x;
#define pure_read(x) cin >> x;
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll n;
string s;

int main() {
  cin >> n >> s;
  vector<ll> gaps;
  ll prevGap = -1;
  for (ll i = 0; i < n; i++) {
    if (s[i] == '1' && prevGap != -1) {
      gaps.push_back(prevGap);
      prevGap = 0;
    } else if (s[i] == '0') {
      prevGap++;
      if (prevGap == 0) {
        prevGap++;
      }
    }
  }
  if (prevGap > 0) {
    gaps.push_back(prevGap);
  }
  for (auto gap : gaps) {
    cout << gap << "\n";
  }
  return 0;
}