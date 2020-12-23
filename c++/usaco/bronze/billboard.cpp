#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Rect {
  int x2, y2, x1, y1;
};

int overlap(Rect a, Rect b) {
  return max(0, min(a.x2, b.x2) - max(a.x1, b.x1)) * max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
}

int area(Rect a) {
  return (a.x1 - a.x2) * (a.y1 - a.y2);
}

int main() {
  Rect a, b, c;
  cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
  cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
  cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;
  cout << area(a) + area(b) - overlap(a, c) - overlap(b, c);
}