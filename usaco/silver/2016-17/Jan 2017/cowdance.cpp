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

bool works(vector<int> l, int k, int t) {
  int last = 0;
  priority_queue<int> pq;
  for (int i = 0; i < l.size(); i++) {
    if (pq.size() == k) {
      last = -pq.top();
      pq.pop();
    }
    if (last + l[i] > t) {
      return false;
    }
    pq.push(-last - l[i]);
  }
  return true;
}

int main() {
  setIO("cowdance");
  int n, t;
  cin >> n >> t;
  vector<int> l(n);
  for (auto &c : l) cin >> c;
  int lo = 1, hi = n;  // key: problem tells us that K = N works every time
  // we can binary search because it is monotonic since if K works then K + 1 must work
  // because one extra spot cannot make the cows T larger
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (works(l, mid, t)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
}