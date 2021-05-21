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
  int n, d;
  vector<int> A(n);
  cin >> n;
  ll reward = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> d;
    reward += d;
  }
  sort(all(A));
  int f = 0;
  for (int i = 0; i < n; i++) {
    f += A[i];
    reward -= f;
  }
  cout << reward << endl;
  return 0;
}