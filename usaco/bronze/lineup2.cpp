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

vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<pair<string, string>> constraints;

ll where(string name) {
  for (ll i = 0; i < cows.size(); i++) {
    if (cows[i] == name) return i;
  }
  return -1;
}

bool arrangement_works() {
  for (pair<string, string> a : constraints) {
    if (abs(where(a.first) - where(a.second)) != 1) {
      return false;
    }
  }
  return true;
}

int main() {
  setIO("lineup");
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    string a, _, b;
    cin >> a >> _ >> _ >> _ >> _ >> b;
    constraints.push_back({a, b});
  }
  do {
    if (arrangement_works()) {
      for (string cow : cows) {
        cout << cow << endl;
      }
      break;
    }
  } while (next_permutation(all(cows)));
  return 0;
}