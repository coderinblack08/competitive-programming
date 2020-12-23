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
  setIO("tttt");
  set<set<char>> team;
  set<set<char>> indv;
  array<array<char, 3>, 3> arr;
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 3; j++) {
      cin >> arr[i][j];
    }
  }
  set<char> s;
  for (ll i = 0; i < 3; i++) {
    // for each row
    s.insert(all(arr[i]));
    if (s.size() == 2) {
      team.insert(s);
    } else if (s.size() == 1) {
      indv.insert(s);
    }
    s = {};
    for (ll j = 0; j < 3; j++) {
      s.insert(arr[j][i]);
    }
    if (s.size() == 2) {
      team.insert(s);
    } else if (s.size() == 1) {
      indv.insert(s);
    }
    s = {};
  }
  for (ll j = 0; j < 2; j++) {
    for (ll i = 0; i < 3; i++) {
      if (j == 0) {
        s.insert(arr[i][i]);
      } else {
        s.insert(arr[i][2 - i]);
      }
    }
    if (s.size() == 2) {
      team.insert(s);
    } else if (s.size() == 1) {
      indv.insert(s);
    }
  }
  cout << indv.size() << endl
       << team.size() << endl;
  return 0;
}