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
  setIO("homework");
  int n;
  cin >> n;
  ll p[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  ll m[n + 1], s[n + 1];
  m[n] = INT_MAX;
  s[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    m[i] = min(p[i], m[i + 1]);
    s[i] = s[i + 1] + p[i];
  }
  double max_score = 0;
  for (int i = 0; i < n; i++) {
    if (i) {
      max_score = max(max_score, double(s[n - i - 1] - m[n - i - 1]) / i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      double score = double(s[n - i - 1] - m[n - i - 1]) / i;
      if (score == max_score) {
        cout << n - i - 1 << endl;
      }
    }
  }
  return 0;
}