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
  setIO("haybales");
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(all(A));
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << upper_bound(all(A), b) - lower_bound(all(A), a) << endl;
  }
  return 0;
}