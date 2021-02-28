#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct V {
  char d;
  ll x, y;
} a[100];

struct E {
  int win;
  ll time;
  ll time2;
  int a, b;
};

bool cmp(E a, E b) {
  return a.time < b.time;
}

int n;

long long ans[100];
vector<E> updates;
bool alive[100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i].d >> a[i].x >> a[i].y;
    ans[i] = 1LL << 50;  // set answer to be huge
    alive[i] = 1;        // set alive to be true at start
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i].d == a[j].d) continue;  // same distance, skip since x and y can't be the same
      int A = i;
      int B = j;
      if (a[A].d != 'N') swap(A, B);  // WLOG, we can make sure that first north and second faces south
      if (a[B].x < a[A].x && a[A].y < a[B].y) {
        ll distE = a[A].x - a[B].x;  // distance to center
        ll distN = a[B].y - a[A].y;  // distance to center
        if (distE < distN) {
          updates.push_back({0, distE, distN, A, B});
          // E: winner (north stopped = 0, else 1), grass ate by E, grass ate by N, north cow, south cow
        } else if (distN < distE) {
          updates.push_back({1, distN, distE, A, B});
          // same as above but east (stopped), first time is always first one their's time, ..
        }
        // if they are on same block at same time, don't do anything :D
      }
    }
  }

  sort(updates.begin(), updates.end(), cmp);
  // sort updates by time occurred, this way we can make sure b doesn't get intersected before the thing happens

  for (auto& W : updates) {
    if (W.win == 0 && ans[W.b] > W.time) {         // if north got stopped but east didn't get stopped before the intersection
      ans[W.a] = min(ans[W.a], W.time2);           // set answer to min of prev answer
    } else if (W.win == 1 && ans[W.a] > W.time) {  // same deal, but instead east got stopped
      ans[W.b] = min(ans[W.b], W.time2);           // set answer to min of prev answer
    }
  }

  for (int i = 0; i < n; i++) {
    cout << (ans[i] == (1LL << 50) ? "Infinity" : to_string(ans[i])) << '\n';
    // output the answers
  }
}