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
  setIO("photo");
  int n;
  cin >> n;
  vector<int> b(n - 1);
  for (auto &c : b) cin >> c;
  for (int i = 1; i < b[0]; i++) {
    set<int> used;
    int prev = i;
    bool works = true;
    vector<int> l;
    l.push_back(i);
    for (int j = 0; j < n - 1; j++) {
      if (used.count((b[j] - prev))) {
        works = false;
      } else {
        used.insert(b[j] - prev);
      }
      l.push_back(b[j] - prev);
      prev = b[j] - prev;
    }
    if (works) {
      for (int j = 0; j < n; j++) {
        cout << l[j];
        if (j != n - 1) {
          cout << " ";
        }
      }
      cout << endl;
      return 0;
    }
  }
  return 0;
}