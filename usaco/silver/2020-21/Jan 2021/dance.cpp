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
  // setIO();
  int n, k;
  cin >> n >> k;
  vector<int> cows(n + 1, 0);
  vector<int> viewed[n + 1];
  for (int i = i; i <= n; i++) {
    cows[i] = i;
    viewed[i].push_back(i);
  }
  for (int i = 1; i <= k; i++) {
    int a, b;
    cin >> a >> b;
    swap(cows[a], cows[b]);
    viewed[cows[a]].push_back(a);
    viewed[cows[b]].push_back(b);
  }
  vector<int> ans(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (cows[i] != 0) {
      vector<int> cycle;
      int j = i;
      while (cows[j] != 0) {
        cycle.push_back(j);
        j = cows[j];
        cows[cycle[cycle.size() - 1]] = 0;
      }
      set<int> s;
      for (int cow : cycle) {
        for (int c : viewed[cow]) {
          s.insert(c);
        }
      }
      // for (auto it = s.begin(); it != s.end(); it++) {
      //   cout << *it << " ";
      // }
      // cout << endl;
      for (int cow : cycle) {
        ans[cow] = s.size();
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}