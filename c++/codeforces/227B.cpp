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
  int n, m;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mp[a] = i;
  }
  cin >> m;
  ll v = 0, p = 0;
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    v += mp[b] + 1;
    p += n - mp[b];
  }
  std::cout << v << " " << p << endl;
  return 0;
}