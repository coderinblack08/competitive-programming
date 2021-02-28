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
  setIO("notlast");
  ll n;
  cin >> n;
  map<string, ll> prod;
  for (ll i = 0; i < n; i++) {
    string cow;
    ll amount;
    cin >> cow >> amount;
    prod[cow] += amount;
  }
  vector<pair<ll, string>> cows;
  for (auto it = prod.begin(); it != prod.end(); it++) {
    cows.push_back({it->second, it->first});
  }
  sort(all(cows));
  ll i;
  ll prev = cows[0].first;
  for (i = 0; cows[i].first == prev; i++) {
    prev = cows[i].first;
  }
  if (cows.size() > 1 && i == cows.size()) {
    cout << "Tie" << endl;
  } else if (cows.size() <= 1 && i == cows.size()) {
    cout << cows[i - 1].second << endl;
  } else {
    cout << cows[i].second << endl;
  }
  return 0;
}