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
  int n, t;
  cin >> n >> t;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int ans = 0;
  int time = A[0];
  int books = 1;
  int l = 0, r = 0;
  while (r < n) {
    if (time <= t) {
      books++;
      time += A[++r];
    } else {
      books--;
      ans = max(ans, books);
      time -= A[l++];
    }
  }
  ans = max(ans, books - 1);
  cout << ans << endl;
  return 0;
}