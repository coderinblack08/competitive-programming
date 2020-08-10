#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (ll i = *max_element(A.begin(), A.end()); i > 0; --i) {
    string s;
    for (auto c: A) {
      if (c == i) {
        s += "*** ";
      } else if (c > i) {
        s += "* * ";
      } else {
        s += "    ";
      }
    }
    cout << s.substr(0, s.length() - 1) << "\n";
  }
  return 0;
}