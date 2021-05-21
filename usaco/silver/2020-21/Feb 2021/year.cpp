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
  int n, k;
  cin >> n >> k;
  k -= 1;
  vector<int> anc(n + 1);
  anc[0] = 0;
  int start = 0;
  for (int i = 1; i <= n; i++) {
    cin >> anc[i];
    start = max(start, anc[i]);
  }
  while (start % 12 != 0) start++;
  sort(all(anc));
  vector<int> gaps(n);
  for (int i = 0; i < n; i++) {
    int l = anc[i], r = anc[i + 1];
    while (l % 12 != 0) l++;
    while (r % 12 != 0) r--;
    gaps[i] = r - l;
  }
  sort(all(gaps));
  reverse(all(gaps));
  int j = 0;
  while (k) {
    start -= gaps[j++];
    k--;
  }
  cout << start;
  return 0;
}