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
  setIO("highcard");
  int n;
  cin >> n;
  set<int> s1, s2;
  for (int i = 1; i <= 2 * n; i++) {
    s1.insert(i);
  }
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s1.erase(a);
    s2.insert(a);
  }
  vector<int> d1, d2;
  for (auto it = s1.begin(); it != s1.end(); it++) {
    d1.push_back(*it);
  }
  for (auto it = s2.begin(); it != s2.end(); it++) {
    d2.push_back(*it);
  }
  sort(all(d1));
  sort(all(d2));
  int a = 0, b = 0;
  int sol = 0;
  while (a < n && b < n) {
    if (d1[a] > d2[b]) {
      a++;
      b++;
      sol++;
    }
    if (d1[a] < d2[b]) {
      a++;
    }
  }
  cout << sol << endl;
  return 0;
}