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
  setIO("circlecross");
  string road;
  cin >> road;
  ll ans = 0;
  for (ll a = 0; a < road.length(); a++) {
    for (ll b = a + 1; b < road.length(); b++) {
      for (ll c = b + 1; c < road.length(); c++) {
        for (ll d = c + 1; d < road.length(); d++) {
          ans += road[a] == road[c] && road[b] == road[d];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}