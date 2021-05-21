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
  setIO("berries");
  int n, k;
  cin >> n >> k;
  int B[n];
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  sort(B, B + n);
  int best = 0;
  for (int e = 1; e <= 1000; e++) {
    int full = 0;
    int A[n];
    for (int i = 0; i < n; i++) {
      full += B[i] / e;
      A[i] = B[i] % e;
    }
    if (full < k / 2) {
      continue;
    }
    int left = k / 2;
    int score = 0;
    if (full > k / 2) {
      int take = full - (k / 2);
      if (take > left) {
        take = left;
      }
      left -= take;
      score += e * take;
    }
    sort(A, A + n);
    for (int i = n - 1; i >= 0 && left > 0; i--) {
      left--;
      score += A[i];
    }
    best = max(best, score);
  }
  std::cout << best << endl;
  return 0;
}