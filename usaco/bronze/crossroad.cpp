#include <bits/stdc++.h>
using namespace std;

struct Cow {
  int id, side;
};

bool comp(Cow a, Cow b) {
  return a.id < b.id;
}

int main() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
  int n;
  cin >> n;
  Cow r[n];
  for (int i = 0; i < n; i++)
    cin >> r[i].id >> r[i].side;
  sort(r, r + n, comp);
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (r[i + 1].id == r[i].id && i != n - 1) {
      if (r[i].side != r[i + 1].side) {
        t++;
      }
    }
  }
  cout << t;
  return 0;
}