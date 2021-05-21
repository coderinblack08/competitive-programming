#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second > b.second;
}

int main() {
  setIO("rental");
  ll n, m, r;
  cin >> n >> m >> r;

  vector<ll> cows(n);
  for (ll i = 0; i < n; i++) {
    cin >> cows[i];
  }

  vector<pair<ll, ll>> store(m);
  for (ll i = 0; i < m; i++) {
    cin >> store[i].first >> store[i].second;
  }

  vector<ll> rent(r);
  for (ll i = 0; i < r; i++) {
    cin >> rent[i];
  }

  sort(store.begin(), store.end(), comp);
  sort(cows.begin(), cows.end());
  sort(rent.begin(), rent.end());

  for (ll i = r - 2; i >= 0; i--) {
    rent[i] += rent[i + 1];
  }

  ll sold = 0, ans = rent[r - min(n, r)];
  ll curStore = 0;
  for (ll c = n - 1; c >= 0; c--) {
    while (cows[c] > 0 && curStore < m) {
      if (store[curStore].first <= cows[c]) {
        sold += store[curStore].first * store[curStore].second;
        cows[c] -= store[curStore].first;
        curStore++;
      } else {
        sold += store[curStore].second * cows[c];
        store[curStore].first -= cows[c];
        cows[c] = 0;
      }
    }
    ans = max(ans, sold + (c == 0 ? 0 : rent[r - min(c, r)]));
  }
  cout << ans << endl;
  return 0;
}