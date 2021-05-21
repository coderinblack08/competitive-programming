#include <bits/stdc++.h>
using namespace std;

const int INF = 1e18;
#define int long long

int32_t main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<int> A(n), B(m);
  auto sign_a = [&](int x) { return x % 2 == 0 ? 1 : -1; };
  auto sign_b = [&](int x) { return -sign_a(x); };

  int a_sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    a_sum += sign_a(i) * A[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> B[i];
  }

  vector<int> b_sum(m);
  multiset<int> bs;
  for (int i = 0; i < n; i++) {
    b_sum[0] += sign_b(i) * B[i];
  }
  bs.insert(b_sum[0]);
  for (int j = 0; j < m - n; j++) {
    b_sum[j + 1] = -(b_sum[j] + B[j]) + sign_b(n - 1) * B[j + n];
    bs.insert(b_sum[j + 1]);
  }

  int l, r, x;
  auto ans = [&]() -> void {
    auto ub = bs.upper_bound(-a_sum);
    int ret = INF;
    if (ub != bs.end()) ret = min(ret, abs(a_sum + *ub));
    if (ub != bs.begin()) ret = min(ret, abs(a_sum + *--ub));
    cout << ret << endl;
  };
  ans();
  while (q--) {
    cin >> l >> r >> x;
    l--, r--;
    if ((r - l) % 2 == 0) {
      a_sum += sign_a(l) * x;
    }
    ans();
  }
}