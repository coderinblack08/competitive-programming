#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll ans = 0;
  ll n, m;
  cin >> n >> m;
  while (n % 2 == 1 && m % 2 == 1) {
    ans = ans * 4 + 1;
    n /= 2;
    m /= 2;
  }
  cout << ans;
  return 0;
}