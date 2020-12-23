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
  ll n, m;
  cin >> n >> m;
  vector<string> spotty(n), plain(n);
  for (ll i = 0; i < n; i++) {
    cin >> spotty[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> plain[i];
  }
  set<string> explains_spottiness, explains_plain;
  set<string> ans;
  for (ll a = 0; a < m; a++) {
    for (ll b = a + 1; b < m; b++) {
      for (ll c = b + 1; c < m; c++) {
        for (ll i = 0; i < n; i++) {
          string genome;
          genome += spotty[i][a] + spotty[i][b] + spotty[i][c];
          explains_spottiness.insert(genome);
          genome = plain[i][a] + plain[i][b] + plain[i][c];
          explains_plain.insert(genome);
        }
        for (auto it = explains_spottiness.begin(); it != explains_spottiness.end(); it++) {
          if (!explains_plain.count(*it)) {
            ans.insert(*it);
          }
        }
      }
    }
  }
  cout << ans.size() << endl;
  return 0;
}