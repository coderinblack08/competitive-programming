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

const int MX = 1e5;
int cow[MX];

int main() {
  setIO("lemonade");
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cow[i];
  }
  sort(cow, cow + n, greater<int>());
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (cow[i] < c) {
      break;
    }
    c++;
  }
  cout << c << endl;
  return 0;
}