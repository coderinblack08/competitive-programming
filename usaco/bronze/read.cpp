#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int tv = 0, s, t, r;
    cin >> s >> t >> r;
    int total = n / (s * t);
    int remainder = n % (s * t);
    tv += total * (r + t) + (remainder + s - 1) / s;
    if (remainder == 0) tv -= r;
    cout << tv << "\n";
  }
  return 0;
}