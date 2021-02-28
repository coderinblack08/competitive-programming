/*
ID: kevinlu4
TASK: palsquare
LANG: C++14
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

bool is_pali(string a) {
  for (int l = 0, r = a.length() - 1; l < r; l++, r--) {
    if (a[l] != a[r]) {
      return false;
    }
  }
  return true;
}

string to_base(int i, int b) {
  string result = "";
  while (i > 0) {
    int remainder = i % b;
    result += "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[remainder];
    i -= remainder;
    i /= b;
  }
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  setIO("palsquare");
  int b;
  cin >> b;
  for (int i = 1; i <= 300; i++) {
    if (is_pali(to_base(pow(i, 2), b))) {
      cout << to_base(i, b) << " " << to_base(pow(i, 2), b) << endl;
    }
  }
  return 0;
}