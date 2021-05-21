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
  setIO("diamond");
  int n, k;
  cin >> n >> k;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  int canTake[n];
  int l = 0, r = 0;
  for (; l < n; l++) {
    while (r < n && A[r] - A[l] <= k) r++;
    canTake[l] = r - l;
  }
  int maxAfter[n + 1];
  maxAfter[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    maxAfter[i] = max(maxAfter[i + 1], canTake[i]);
  }
  int ans = 0;
  for (int l = 0; l < n; l++) {
    ans = max(ans, canTake[l] + maxAfter[l + canTake[l]]);
  }
  cout << ans << endl;
  return 0;
}