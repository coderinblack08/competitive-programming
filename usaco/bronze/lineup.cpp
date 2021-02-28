#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll n;
vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<pair<string, string>> beside;

ll where(string name) {
  for (ll i = 0; i < 8; i++) {
    if (cows[i] == name) {
      return i;
    }
  }
  return -1;
}

bool arangmentWorks() {
  for (ll i = 0; i < n; i++) {
    if (abs(where(beside[i].first) - where(beside[i].second)) != 1) {
      return false;
    }
  }
  return true;
}

int main() {
  setIO("lineup");
  cin >> n;
  string name, temp, partner;
  for (ll i = 0; i < n; i++) {
    cin >> name >> temp >> temp >> temp >> temp >> partner;
    beside.push_back({name, partner});
  }
  do {
    if (arangmentWorks()) {
      for (ll i = 0; i < 8; i++) {
        cout << cows[i] << "\n";
      }
      break;
    }
  } while (next_permutation(cows.begin(), cows.end()));

  return 0;
}