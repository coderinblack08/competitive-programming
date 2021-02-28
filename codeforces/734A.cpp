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

int main() {
  setIO();
  int n;
  string s;
  cin >> n >> s;
  int a = 0, d = 0;
  for (char& c : s) {
    if (c == 'A') {
      a++;
    } else {
      d++;
    }
  }
  if (a > d) {
    cout << "Anton" << endl;
  } else if (d > a) {
    cout << "Danik" << endl;
  } else {
    cout << "Friendship" << endl;
  }
  return 0;
}