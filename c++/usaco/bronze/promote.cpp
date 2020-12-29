#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);
  int b1, b2, s1, s2, g1, g2, p1, p2;
  cin >> b1 >> b2 >> s1 >> s2 >> g1 >> g2 >> p1 >> p2;
  cout << s2 - s1 + g2 - g1 + p2 - p1 << "\n"
       << g2 - g1 + p2 - p1 << "\n"
       << p2 - p1;
}