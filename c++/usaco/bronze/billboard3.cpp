#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

struct Rect {
  int x1, y1, x2, y2;
};

int overlap(Rect a, Rect b) {
  return max(0, min(a.x2, b.x2) - max(a.x1, b.x1)) * max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
}

int area(Rect a) {
  return (a.x1 - a.x2) * (a.y1 - a.y2);
}

int main() {
  vector<Rect> A(3);
  for (ll i = 0; i < A.size(); i++) {
    cin >> A[i].x1 >> A[i].y1 >> A[i].x2 >> A[i].y2;
  }
  cout << area(A[0]) + area(A[1]) - overlap(A[0], A[2]) - overlap(A[1], A[2]) << endl;
  return 0;
}