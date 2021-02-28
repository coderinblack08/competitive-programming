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
  ll n, l;
  cin >> n >> l;
  vector<ll> seq(l);
  for (ll i = 0; i < l; i++) {
    cin >> seq[i];
  }
  vector<ll> list(n, 0);
  ll count = n, pos = -1, cur = 0;
  while (count > 1) {
    ll term = seq[cur];
    while (term > 0) {
      pos = (pos + 1) % n;
      if (list[pos] == 0) {
        term--;
      }
    }
    list[pos] = 1;
    count--;
    cur = (cur + 1) % l;
  }

  for (ll i = 0; i < n; i++) {
    if (list[i] == 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}