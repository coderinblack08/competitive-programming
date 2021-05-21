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

const int MOD = static_cast<ll>(1e9 + 9);

int main() {
  setIO();
  int n, d;
  cin >> n >> d;
  int block[n];
  for (int i = 0; i < n; i++) {
    cin >> block[i];
  }
  sort(block, block + n);
  ll ans = 1;
  for (int i = 1, j = 0; i < n; i++) {
    while (j < i && block[j] + d < block[i]) j++;
    ans = ((i - j + 1) * ans) % MOD;
  }
  cout << ans << endl;
  return 0;
}