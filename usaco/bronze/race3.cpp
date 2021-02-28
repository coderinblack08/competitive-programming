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
  int k, n;
  cin >> k >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int dist = 0, time = 0;
    for (int v = 1;; v++) {
      dist += v;
      time++;
      if (dist >= k) break;
      if (v >= x) {
        dist += v;
        time++;
        if (dist >= k) break;
      }
    }
    cout << time << endl;
  }
  return 0;
}