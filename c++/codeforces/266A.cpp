#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;

void swap(ll i) {
  char temp = s[i + 1];
  s[i + 1] = s[i];
  s[i] = temp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, t;
  cin >> n >> t >> s;
  for (ll b = 0; b < t; ++b) {
    for (ll i = 0; i < n - 1; ++i) {
      if (s[i] == 'B' && s[i + 1] == 'G') {
        swap(i);
        ++i;
      }
    }
  }
  cout << s;
  return 0;
}