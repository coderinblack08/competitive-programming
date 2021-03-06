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
  vector<int> h(n);
  for (auto& a : h) cin >> a;
  int tot = h[0], en = 0;
  for (int i = 0; i < n - 1; i++) {
    if (h[i] >= h[i + 1]) {
      en += h[i] - h[i + 1];
    } else {
      if (en >= h[i + 1] - h[i]) {
        en -= h[i + 1] - h[i];
      } else {
        tot += h[i + 1] - h[i] - en;
        en = 0;
      }
    }
  }
  cout << tot << endl;
  return 0;
}