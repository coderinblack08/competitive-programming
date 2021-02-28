#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int s[100] = {0}, bs[100] = {0}, ps = 0, pl = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < a; j++) {
      s[j + ps] = b;
    }
    ps += a;
  }
  for (int j = 0; j < m; j++) {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
      bs[i + pl] = b;
    pl += a;
  }
  int ms = 0;
  for (int i = 0; i < 100; i++) {
    ms = max(ms, bs[i] - s[i]);
  }
  cout << ms;
  return 0;
}