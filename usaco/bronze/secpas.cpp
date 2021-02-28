#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool sq(int n) {
  long double sr = sqrt(n);
  return ((sr - floor(sr)) == 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, total = 0;
  cin >> n;
  for (int s1 = 0; s1 <= sqrt(n); s1++) {
    for (int s2 = 0; s2 <= sqrt(n); s2++) {
      for (int s3 = 0; s3 <= sqrt(n); s3++) {
        int a = pow(s1, 2) + pow(s2, 2) + pow(s3, 2);
        if (sq(n - a)) total++;
      }
    }
  }
  cout << total;
  return 0;
}