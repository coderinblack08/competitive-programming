#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  map<char, string> m;
  for (char c: s) {
    if(m.count(c)) {
      m[c] += c;
    } else {
      m[c] = c;
    }
  }
  string start = "", end = "", mid = "";
  for (auto c: m) {
    if (c.second.length() % 2 == 1 && mid != "") {
      cout << "NO SOLUTION" << "\n";
    } else if (c.second.length() % 2 == 1) {
      mid = c.second;
    } else {
      start = c.second.substr(0, c.second.length() / 2) + start;
      end += c.second.substr(0, c.second.length() / 2);
    }
  }
  cout << start + mid + end << "\n";
  return 0;
}