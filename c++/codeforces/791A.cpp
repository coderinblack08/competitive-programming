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

int main() {
  setIO();
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 0; a <= b; i++) {
    cnt++;
    a *= 3;
    b *= 2;
  }
  cout << cnt << endl;
  return 0;
}