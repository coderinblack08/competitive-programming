#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  string a, b;
  cin >> a >> b;
  for (ll i = 0; i < a.length(); ++i) {
    for (ll j = i + 1; j < a.length(); ++j) {
      swap(a[i], a[j]);
      if (a == b) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}