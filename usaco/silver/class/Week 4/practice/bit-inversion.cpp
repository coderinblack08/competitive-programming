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

string s;
int m;
set<int> dif;
multiset<int> ret;

void modify(int x) {
  if (x == 0 || x == s.length()) return;
  auto it = dif.find(x);
  if (it != dif.end()) {
    int a = *prev(it), b = *next(it);
    ret.erase(ret.find(x - a));
    ret.erase(ret.find(b - x));
    ret.insert(b - a);
    dif.erase(x);
  } else {
    it = dif.insert(x).first;
    int a = *prev(it), b = *next(it);
    ret.erase(ret.find(b - a));
    ret.insert(x - a);
    ret.insert(b - x);
  }
}

int main() {
  setIO();
  cin >> s >> m;
  dif.insert(0);
  dif.insert(s.length());
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] != s[i + 1]) dif.insert(i + 1);
  }
  for (auto it = dif.begin(); next(it) != dif.end(); it++) {
    ret.insert(*next(it) - *it);
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    modify(x - 1);
    modify(x);
    cout << *ret.rbegin() << " ";
  }
  return 0;
}