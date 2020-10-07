#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  a[0] = 0;
  int p = 0, t = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == -1) p++;
    if (a[i] == 0) {
      p++;
      t++;
    }
    if (a[i] > 0) {
      for (int j = 0; j <= a[i]; j++) {
        if (a[i - j] != a[i] - j && a[i - j] != -1) {
          cout << -1;
          return 0;
        } else {
          a[i - j] = a[i] - j;
        }
      }
    }
  }
  cout << t << " " << p;
  return 0;
}