#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ifstream fin("3.txt");

  vector<string> G;
  ll answer = 0;

  while (true) {
    if (fin.eof()) {
      break;
    }
    string temp;
    getline(fin, temp);
    G.push_back(temp);
  }

  ll x = 0, y = 0;

  while (y < G.size()) {
    x += 3;
    y += 1;

    if (G[y].length() != 0) {
      if (G[y][x % G[y].length()] == '#') {
        answer++;
      }
    }
  }

  cout << "Part 1: " << answer << endl;

  answer = 1;

  vector<pair<ll, ll>> slopes = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};

  for (ll i = 0; i < slopes.size(); i++) {
    x = 0, y = 0;
    ll count = 0;
    while (y < G.size()) {
      x += slopes[i].first;
      y += slopes[i].second;
      if (G[y].length() != 0) {
        if (G[y][x % G[y].length()] == '#') {
          count++;
        }
      }
    }
    answer *= count;
  }

  cout << "Part 2: " << answer << endl;

  fin.close();
  return 0;
}