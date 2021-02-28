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
  string result;
  result += s[0];
  for (int i = 1; i < n; i++) {
    if (i % 2) {
      result = s[i] + result;
    } else {
      result += s[i];
    }
  }
  if (n % 2) {
    cout << result << endl;
  } else {
    reverse(all(result));
    cout << result << endl;
  }
  return 0;
}