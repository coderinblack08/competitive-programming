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

int n, t_max;
int d[static_cast<int>(1e4 + 1)];
bool check(int k) {
  int prev = 0;
  priority_queue<int, vector<int>, greater<int> > q;
  for (int i = 0; i < n; i++) {
    if (q.size() == k) {
      prev = q.top();
      q.pop();
    }
    if (prev + d[i] > t_max) {
      return false;
    }
    q.push(prev + d[i]);
  }
  return true;
}

int main() {
  setIO("cowdance");
  cin >> n >> t_max;
  for (int i = 0; i < n; i++) cin >> d[i];
  int lo = 1, hi = n;
  while (lo < hi) {
    int k = (hi + lo) / 2;
    int t = 0;
    if (check(k)) {
      hi = k;
    } else {
      lo = k + 1;
    }
  }
  cout << lo;
  return 0;
}