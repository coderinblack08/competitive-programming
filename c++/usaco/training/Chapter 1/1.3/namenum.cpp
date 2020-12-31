/*
ID: kevinlu4
TASK: namenum
LANG: C++11
*/

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

int main() {
  setIO("namenum");
  ifstream dict("dict.txt");
  string s, name;
  cin >> s;
  vector<string> v = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"}, cbm, names;

  for (char& c : s) {
    cbm.push_back(v[c - '2']);
  }

  while (dict >> name) {
    if (name.length() == s.length()) {
      bool same = true;
      for (int i = 0; i < s.length(); i++) {
        if (cbm[i].find(name[i]) == cbm[i].npos) {
          same = false;
          break;
        }
      }
      if (same) {
        names.push_back(name);
      }
    }
  }
  if (names.size()) {
    for (auto& n : names) {
      cout << n << endl;
    }
  } else {
    cout << "NONE" << endl;
  }
  return 0;
}