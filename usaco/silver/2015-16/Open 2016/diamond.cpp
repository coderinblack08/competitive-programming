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

const int MX = 5e4;

int d[MX];
int group_size[MX];
int max_group_after[MX + 1];

int main() {
  setIO("diamond");
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  sort(d, d + n);
  int l = 0, r = 0;
  for (; l < n; l++) {
    while (r < n && d[r] - d[l] <= k) r++;
    group_size[l] = r - l;
  }
  max_group_after[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    max_group_after[i] = max(max_group_after[i + 1], group_size[i]);
  }
  int ans = 0;
  for (int l = 0; l < n; l++) {
    ans = max(ans, group_size[l] + max_group_after[l + group_size[l]]);
  }
  cout << ans << endl;
  return 0;
}