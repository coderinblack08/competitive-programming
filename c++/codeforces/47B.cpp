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
  map<char, vector<char>> mp;
  set<char> used;
  for (int i = 0; i < 3; i++) {
    char a, t, b;
    cin >> a >> t >> b;
    if (t == '>') {
      mp[a].push_back(b);
      used.insert(a);
    } else {
      mp[b].push_back(a);
      used.insert(b);
    }
  }
  for (char i = 'A'; i < 'D'; i++) {
    if (!used.count(i)) {
      mp[i] = {};
    }
    for (auto& c : mp[i]) {
      if (find(all(mp[c]), i) != mp[c].end()) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  vector<char> order(3, 'Z');
  for (auto& v : mp) {
    if (order[v.second.size()] != 'Z') {
      cout << "Impossible" << endl;
      return 0;
    } else {
      order[v.second.size()] = v.first;
    }
  }
  for (auto& c : order) cout << c;
  return 0;
}