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
  // setIO("shuffle");
  int n;
  cin >> n;
  int to[n], parent[n] = {0};
  for (int i = 0; i < n; i++) {
    cin >> to[i];
    to[i]--;
    parent[to[i]]++;
  }
  int ans = n;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (parent[i] == 0) {
      q.push(i);
      ans--;
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (--parent[to[cur]] == 0) {
      q.push(to[cur]);
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}