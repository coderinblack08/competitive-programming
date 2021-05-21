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
int n, x[MX], y[MX], a[MX];

bool compareX(int a, int b) {
  if (x[a] == x[b]) return y[a] < y[b];
  return x[a] < x[b];
}

bool compareY(int a, int b) {
  if (y[a] == y[b]) return x[a] < x[b];
  return y[a] < y[b];
}

int main() {
  setIO("split");
  cin >> n;
  multiset<int> allX, allY, leftX, leftY, rightX, rightY;
  for (int i = 0; i < n; i++) {
    a[i] = i;
    cin >> x[i] >> y[i];
    allX.insert(x[i]);
    allY.insert(y[i]);
  }
  sort(a, a + n, compareX);
  int x1 = *allX.rbegin(), x2 = *allX.begin(), y1 = *allY.rbegin(), y2 = *allY.begin();
  ll area = (x1 - x2) * 1LL * (y1 - y2);
  ll ans = 0;
  for (int k = 0; k <= 1; k++) {
    rightX = allX;
    rightY = allY;
    leftX.clear();
    leftY.clear();
    for (int i = 0; i < n; i++) {
      int j = a[i];
      ll areaL = 0, areaR = 0;
      leftX.insert(x[j]);
      leftY.insert(y[j]);
      rightX.erase(rightX.find(x[j]));
      rightY.erase(rightY.find(y[j]));
      x1 = *leftX.begin();
      y1 = *leftY.begin();
      x2 = *leftX.rbegin();
      y2 = *leftY.rbegin();
      areaL = (x2 - x1) * 1LL * (y2 - y1);
      if (!rightX.empty()) {
        x1 = *rightX.begin();
        y1 = *rightY.begin();
        x2 = *rightX.rbegin();
        y2 = *rightY.rbegin();
        areaR = (x2 - x1) * 1LL * (y2 - y1);
      }
      ans = max(ans, area - (areaL + areaR));
    }
    sort(a, a + n, compareY);
  }
  cout << ans << endl;
  return 0;
}