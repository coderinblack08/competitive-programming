#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

vector<string> split(string str) {
  vector<string> result;
  stringstream ss(str);
  string word;

  while (ss >> word) {
    result.push_back(word);
  }
  return result;
}

int main() {
  return 0;
}