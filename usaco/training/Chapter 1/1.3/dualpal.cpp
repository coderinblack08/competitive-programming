/*
ID: kevinlu4
TASK: dualpal
LANG: C++11
*/
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

string to_base(int i, int b) {
  string result = "";
  while (i > 0) {
    int remainder = i % b;
    result += remainder + '0';
    i -= remainder;
    i /= b;
  }
  reverse(result.begin(), result.end());
  return result;
}

bool works(int s) {
  int cnt = 0;
  for (int i = 2; i <= 10; i++) {
    string a = to_base(s, i);
    string b(a.rbegin(), a.rend());
    if (a == b) {
      cnt++;
    }
  }
  if (cnt >= 2) {
    return true;
  }
  return false;
}

int main() {
  setIO("dualpal");
  int n, s;
  cin >> n >> s;
  s++;
  while (n) {
    if (works(s)) {
      cout << s << endl;
      n--;
    }
    s++;
  }
  return 0;
}