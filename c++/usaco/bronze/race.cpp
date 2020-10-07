#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);
  int k, n;
  cin >> k >> n;
  for (int i = 0; i < n; ++i) {
    int x, left = 0, right = 0, time = 0, speed = 1;
    cin >> x;
    while (true) {
      left += speed;
      time++;
      if (left + right >= k) {
        cout << time << "\n";
        break;
      }
      if (speed >= x) {
        right += speed;
        time++;
        if (left + right >= k) {
          cout << time << "\n";
          break;
        }
      }
      speed++;
    }
  }
  return 0;
}