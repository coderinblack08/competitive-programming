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
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    int ans = 0;
    set<int> expanded;
    for (auto x : nums) {
      expanded.insert(x);
      for (int y : nums) {
        if (x < y) {
          expanded.insert(y - x);
        }
      }
    }
    for (int a : expanded) {
      for (int b : expanded) {
        for (int c : expanded) {
          if (a <= b && b <= c) {
            set<int> all_nums = {a, b, c, a + b, a + c, b + c, a + b + c};
            bool works = true;
            for (int x : nums) {
              if (!all_nums.count(x)) {
                works = false;
              }
            }
            if (works) {
              ans++;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}