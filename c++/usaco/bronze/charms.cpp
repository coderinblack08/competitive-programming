#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int l, c, n;
  cin >> l >> c >> n;
  for (int i = 0; i < c; i++) {
    int s, p;
    cin >> s >> p;
    cout << abs(p - n) + s << "\n";
  }
  return 0;
}
