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
  vector<pair<int, int>> A;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    A.push_back({a, 1});
    A.push_back({b, -1});
  }
  sort(all(A));
  int ans = 0;
  int customers = 0;
  for (auto c : A) {
    customers += c.second;
    ans = max(ans, customers);
  }
  cout << ans << endl;
  return 0;
}