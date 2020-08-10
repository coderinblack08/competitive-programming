#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c;
  cin >> r >> c;
  vector<vector<int>> OK(R, vector<int>(C, false));
  for (ll i = 0; i < r; i++) {
    string str;
    cin >> str;
    for (ll j = 0; j < c; j++) {
      OK[i][j] = (str[j] == '.');
    }
  }
  return 0;
}