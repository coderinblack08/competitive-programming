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
  setIO("notlast");
  ll n, amount;
  cin >> n;
  string cow;
  vector<string> cows = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
  vector<ll> milkprod(cows.size(), 0);
  for (ll i = 0; i < n; i++) {
    cin >> cow >> amount;
    for (ll j = 0; j < cows.size(); j++) {
      if (cows[i] == cow) {
        milkprod[i] += amount;
      }
    }
  }
  ll secondIndex = 0;
  sort(milkprod.begin(), milkprod.end());
  for (ll i = 1; i < cows.size(); i++) {
    if (milkprod[i] != milkprod[i - 1]) {
      secondIndex = i;
      break;
    }
    if (i == cows.size()) {
      cout << "Tie\n";
    }
  }
  cout << cows[secondIndex] << "\n";
  return 0;
}