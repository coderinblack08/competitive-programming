#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, ans = 0;
  cin >> n;
  while (n) {
    if (n % 10 == 7 || n % 10 == 4) ans++;
    n /= 10;
  }
  if (ans == 7 || ans == 4) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}