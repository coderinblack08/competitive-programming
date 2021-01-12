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
  int n;
  cin >> n;
  string result = "ROYGRBIV";
  string a = "GBIV";
  n -= 8;
  for (int i = 0; i < n / 4; i++) {
    result += a;
    n -= 7;
  }
  for (int i = 0; i < n; i++) {
    result += a[i];
  }
  cout << result << endl;
  return 0;
}