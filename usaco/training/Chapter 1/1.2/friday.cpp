/*
ID: kevinlu4
TASK: friday
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

int month_length[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap_year(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return true;
  }
  return false;
}

int main() {
  setIO("friday");
  int n;
  cin >> n;
  vector<int> freq(7, 0);
  int d = 0;
  for (ll y = 1900; y < 1900 + n; y++) {
    month_length[1] = leap_year(y) ? 29 : 28;  // account of leap years
    for (ll m = 0; m < 12; m++) {
      freq[((d + 12) % 7 + 2) % 7]++;  // we find the date of firday the 13th, also add 2 since Jan 1, 1900 starts on monday (so starts at saturday)
      d += month_length[m];
    }
  }
  for (ll i = 0; i < freq.size(); i++) {
    cout << freq[i];
    if (i == freq.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
  return 0;
}