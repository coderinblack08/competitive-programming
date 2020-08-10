#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m, k, ans = 0, bi = 0;
  cin >> n >> m >> k;
  vector<ll> A(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  vector<ll> B(m, 0);
  for (int i = 0; i < m; ++i) {
    cin >> B[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  for (int i = 0; i < n; ++i) {
    while (bi < m &&  B[bi] < A[i] - k) {
      bi++;
    }
    if (bi < m && A[i] - k <= B[bi] && B[bi] <= A[i] + k) {
      ans++;
      bi++;
    }
  }
  cout << ans << "\n";
  return 0;
}