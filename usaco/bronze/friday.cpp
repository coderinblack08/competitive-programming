/*
ID: kevinlu4
LANG: C++
TASK: friday
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);
  int n;
  int mlen[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int r[7] = {0};
  int d = 0;
  cin >> n;
  for (int y = 1900; y < 1900 + n; y++) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
      mlen[1] = 29;
    else
      mlen[1] = 28;
    for (int m = 0; m < 12; m++) {
      r[((d + 12) % 7 + 2) % 7]++;
      d += mlen[m];
    }
  }
  for (int i = 0; i < 7; i++) {
    if (i != 6)
      cout << r[i] << " ";
    else
      cout << r[i];
  }
  cout << "\n";
  return 0;
}