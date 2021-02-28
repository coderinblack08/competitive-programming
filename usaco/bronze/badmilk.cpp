#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

struct Record {
  int person, milk, time;
};

struct Query {
  int person, time;
};

int main() {
  setIO("badmilk");
  int n, m, d, s;
  cin >> n >> m >> d >> s;
  Record r[d];
  Query q[s];
  for (int i = 0; i < d; i++) {
    cin >> r[i].person >> r[i].milk >> r[i].time;
  }
  for (int i = 0; i < s; i++) {
    cin >> q[i].person >> q[i].time;
  }
  bool good[m] = {true};
  for (int i = 0; i < m; i++) {
    int cur = i + 1, c = 0;
    for (int j = 0; j < s; j++) {
      for (int k = 0; k < d; k++) {
        if (q[j].person == r[k].person && r[k].milk == cur)
          if (r[k].time < q[j].time) {
            c++;
            break;
          }
      }
    }
    if (c != s)
      good[i] = false;
  }
  int best = 0;
  for (int i = 0; i < m; i++) {
    if (good[i]) {
      int c = 0;
      bool taken[n + 1] = {false};
      for (int j = 0; j < d; j++) {
        if (r[j].milk == i + 1 && taken[r[j].person] == false) {
          c++;
          taken[r[j].person] = true;
        }
      }
      best = max(best, c);
    }
  }
  cout << best;
  return 0;
}