#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, t, sum = 0;
  cin >> n;
  ll highest = 0;
  for (ll i = 0; i < n; i++) {
    cin >> t;
    highest = max(highest, t);
    sum += t;
  }
  cout << max(sum, 2 * highest) << endl;
  return 0;
}