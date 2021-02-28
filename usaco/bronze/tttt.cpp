#include <bits/stdc++.h>
using namespace std;

int checkIndividual(char b[3][3], char c) {
  for (int i = 0; i < 3; i++) {
    if (b[i][0] == c && b[i][1] == c && b[i][2] == c)
      return 1;
    if (b[0][i] == c && b[1][i] == c && b[2][i] == c)
      return 1;
  }
  if (b[0][0] == c && b[1][1] == c && b[2][2] == c) return 1;
  if (b[0][2] == c && b[1][1] == c && b[2][1] == c) return 1;
  return 0;
}

bool checkOnly(char ch1, char ch2, char a, char b, char c) {
  if (a != ch1 && a != ch2) return false;
  if (b != ch1 && b != ch2) return false;
  if (c != ch1 && c != ch2) return false;
  if (a != ch1 && b != ch1 && c != ch1) return false;
  if (a != ch2 && b != ch2 && c != ch2) return false;
  return true;
}

int teamWin(char b[3][3], char ch1, char ch2) {
  if (checkOnly(ch1, ch2, b[0][0], b[1][1], b[2][2])) return 1;
  if (checkOnly(ch1, ch2, b[0][2], b[1][1], b[2][0])) return 1;
  for (int i = 0; i < 3; i++) {
    if (checkOnly(ch1, ch2, b[0][i], b[1][i], b[2][i])) return 1;
    if (checkOnly(ch1, ch2, b[i][0], b[i][1], b[i][2])) return 1;
  }
  return 0;
}

int main() {
  char b[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> b[i][j];
  int a1 = 0, a2 = 0;
  for (char ch1 = 'A'; ch1 <= 'Z'; ch1++)
    a1 += checkIndividual(b, ch1);
  for (char ch1 = 'A'; ch1 <= 'Z'; ch1++)
    for (char ch2 = ch1 + 1; ch2 <= 'Z'; ch2++)
      a2 += teamWin(b, ch1, ch2);
  cout << a1 << "\n"
       << a2;
  return 0;
}