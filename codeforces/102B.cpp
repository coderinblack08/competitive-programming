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

string transform(string n) {
  int sum = 0;
  for (int i = 0; i < n.length(); i++) {
    sum += n[i] - '0';
  }
  return to_string(sum);
}

int main() {
  setIO();
  string n;
  cin >> n;
  int t = 0;
  while (n.length() > 1) {
    n = transform(n);
    t++;
  }
  cout << t << endl;
  return 0;
}