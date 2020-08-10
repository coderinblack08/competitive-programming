#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int b[n - 1], d[n - 3];
  for(int i = 0; i < n - 1; ++i) {
    cin >> b[i];
  }
  for(int i = 2; i < n; ++i) {
    d[i] = b[i - 1] - b[i - 2];
  }
  for(int s = 0; s < n; ++s) {
    int a[n];
    bool used[n];
    a[0] = s;
    a[1] = b[0] - s;
    for(int j = 2; j < n; ++j) {
      a[j] = a[j - 2] + d[j];
    }
  }
  return 0;
}