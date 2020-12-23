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
  ll n;
  cin >> n;
  map<string, vector<string>> animals;
  for (ll i = 0; i < n; i++) {
    string type;
    ll k;
    cin >> type >> k;
    vector<string> characteristics;
    for (ll j = 0; j < k; j++) {
      cin >> characteristics[j];
    }
    animals[type] = characteristics;
  }
  set<string> shared;
  for (auto it = animals.begin(); it != animals.end(); it++) {
    vector<string> characteristics = it->second;
    for (ll j = 0; j < characteristics.size(); j++) {
      shared.insert(characteristics[j]);
    }
  }
  ll ans = 0;
  for (auto it = animals.begin(); it != animals.end(); it++) {
    ll count = 0;
    bool has_not_shared = false;
    for (ll j = 0; j < it->second.size(); j++) {
      if (shared.count(it->second[j])) {
        count++;
      } else {
        has_not_shared = true;
      }
    }
    if (!has_not_shared) {
      ans = max(ans, count + 1);
    }
  }
  cout << ans << endl;
  return 0;
}