/*
ID: kevinlu4
TASK: ride
LANG: C++  
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

const int MOD = 47;

int get_val(string s) {
  int ans = 1;
  for (auto& c : s) {
    ans = (ans * (c - 'A' + 1)) % MOD;
  }
  return ans;
}

int main() {
  setIO("ride");
  string comet, group;
  cin >> comet >> group;
  if (get_val(comet) == get_val(group)) {
    cout << "GO" << endl;
  } else {
    cout << "STAY" << endl;
  }
  return 0;
}