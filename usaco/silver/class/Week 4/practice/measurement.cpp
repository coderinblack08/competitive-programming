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

struct measurement {
  int day, cow, change;
};

int main() {
  setIO("measurement");
  int n, g;
  cin >> n >> g;
  vector<measurement> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i].day >> A[i].cow >> A[i].change;
  }
  sort(all(A), [](measurement& a, measurement& b) { return a.day < b.day; });
  map<int, int, greater<int>> counts;
  counts[0] = n + 1;
  map<int, int> mp;

  int ans = 0;
  for (auto& m : A) {
    int& ref = mp[m.cow];
    bool wastop = ref == counts.begin()->first;
    int prevcount = counts[ref]--;
    if (prevcount == 1) {
      counts.erase(ref);
    }
    ref += m.change;
    int iscount = ++counts[ref];
    bool istop = ref == counts.begin()->first;
    if (wastop) {
      if (!istop || prevcount != 1 || iscount != 1) {
        ans++;
      }
    } else if (istop) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}