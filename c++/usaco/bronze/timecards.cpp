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
  ll n, m;
  cin >> n >> m;
  vector<ll> start(n + 1, 0), timespent(n + 1, 0);
  for (ll i = 0; i < m; i++) {
    ll c, hh, mm;
    string keyword;
    cin >> c >> keyword >> hh >> mm;
    ll time = hh * 60 + mm;
    if (keyword == "START") {
      start[c] = time;
    } else {
      timespent[c] += time - start[c];
    }
  }
  for (ll i = 1; i <= n; i++) {
    ll time = timespent[i];
    cout << time / 60 << " " << time % 60 << endl;
  }
  return 0;
}