#include <bits/stdc++.h>
using namespace std;

int n;
int g[10][10];

bool check(int color) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (g[i][j] == color) return true;
  return false;
}

bool overlap(int color1, int color2) {
  int top = n, bottom = 0, left = n, right = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == color2) {
        top = min(top, i);
        bottom = max(bottom, i);
        right = max(right, j);
        left = min(left, j);
      }
    }
  }
  for (int i = top; i <= bottom; i++) {
    for (int j = left; j <= right; j++) {
      if (g[i][j] == color1)
        return true;
    }
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
      g[i][j] = s[j] - '0';
  }
  int c = 0;
  for (int i = 1; i <= 9; i++) {
    if (!check(i))
      continue;
    bool good = true;
    for (int j = 1; j <= 9; j++) {
      if (i != j && check(j) && overlap(i, j))
        good = false;
    }
    if (good) c++;
  }
  cout << c;
  return 0;
}