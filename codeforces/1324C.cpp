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
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> A;
    A.push_back(0);
    for (int i = 0; i < int(s.size()); i++) {
      if (s[i] == 'R') {
        A.push_back(i + 1);
      }
    }
    A.push_back(s.size() + 1);
    int ans = 0;
    for (int i = 0; i < int(A.size()) - 1; i++) {
      ans = max(ans, A[i + 1] - A[i]);
    }
    cout << ans << endl;
  }
  return 0;
}