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
  while (n--) {
    ll p, a, b, c;
    cin >> p >> a >> b >> c;
    cout << min((a - p % a) % a, min((b - p % b) % b, (c - p % c) % c)) << endl;
  }
  return 0;
}