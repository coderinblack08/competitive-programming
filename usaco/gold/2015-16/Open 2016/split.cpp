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

int n, arr[MX], x[MX], y[MX];

bool comp(int a, int b) {
  if (x[a] == x[b]) {
    return y[a] < y[b];
  }
  return x[a] < x[b];
}

bool comp2(int a, int b) {
  if (y[a] == y[b]) {
    return x[a] < x[b];
  }
  return y[a] < y[b];
}

int main() {
  setIO("split");
  cin >> n;
  multiset<int> all_x, all_y, left_x, left_y, right_x, right_y;
  for (int i = 0; i < n; i++) {
    arr[i] = i;
    cin >> x[i] >> y[i];
    all_x.insert(x[i]);
    all_y.insert(y[i]);
  }
  sort(arr, arr + n, comp);

  int x1 = *all_x.rbegin(), x2 = *all_x.begin(), y1 = *all_y.rbegin(), y2 = *all_y.begin();
  ll area = (x1 - x2) * 1LL * (y1 - y2);
  ll ans = 0;

  for (int k = 0; k <= 1; k++) {
    right_x = all_x;
    right_y = all_y;
    left_x.clear();
    left_y.clear();
    for (int i = 0; i < n; i++) {
      int j = arr[i];
      ll area_l = 0, area_r = 0;

      left_x.insert(x[j]);
      left_y.insert(y[j]);
      right_x.erase(right_x.find(x[j]));
      right_y.erase(right_y.find(y[j]));

      x1 = *left_x.begin();
      y1 = *left_y.begin();
      x2 = *left_x.rbegin();
      y2 = *left_y.rbegin();

      area_l = (x2 - x1) * 1LL * (y2 - y1);
      if (!right_x.empty()) {
        x1 = *right_x.begin();
        y1 = *right_y.begin();
        x2 = *right_x.rbegin();
        y2 = *right_y.rbegin();
        area_r = (x2 - x1) * 1LL * (y2 - y1);
      }
      ans = max(ans, area - (area_l + area_r));
    }
    sort(arr, arr + n, comp2);
  }
  cout << ans << endl;
  return 0;
}