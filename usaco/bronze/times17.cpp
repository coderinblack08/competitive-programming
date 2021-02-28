#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string n = "0000" + s, m = s + "0000";
  int r[n.length() + 1] = {0};
  int l = sizeof(r) / sizeof(r[0]);
  for (int i = l - 1; i > 0; i--) {
    r[i] += (n[i - 1] - '0') + (m[i - 1] - '0');
    if (r[i] >= 2) {
      r[i] -= 2;
      r[i - 1]++;
    }
  }
  int i = 0;
  if (r[0] == 0) i++;
  for (; i < l; i++)
    cout << r[i];
  return 0;
}