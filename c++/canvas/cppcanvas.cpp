#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string n = "1";
  while (stoi(n) % 19LL != 0) {
    n += "1";
  }
  cout << n;
  return 0;
}